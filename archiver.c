//
// Created by Abbit on 04/06/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "archiver.h"
#include "files.h"
#include "settings.h"
#include "huffman.h"

int compareFreqTableCells(const void *a, const void *b) {
    WordInfo x = *(WordInfo *) a;
    WordInfo y = *(WordInfo *) b;

    return (x.frequency > y.frequency) - (x.frequency < y.frequency);
}


FreqTable getFreqTable(ConcatedFile *file) {
    FreqTable freqTable;
    freqTable.length = WORD_CAPATCITY;
    freqTable.table = malloc(freqTable.length * sizeof(WordInfo));

    for (uint64_t i = 0; i < freqTable.length; ++i) {
        freqTable.table[i].word = i;
        freqTable.table[i].frequency = 0;
    }

    for (int k = 0; k < file->filesCount; ++k) {
        rewind(file->files[k]);

        for (uint64_t i = 0; i < file->fileSizeList[k]; ++i) {
            WORD buffer;

            fread(&buffer, sizeof(buffer), 1, file->files[k]);

            freqTable.table[buffer].frequency++;
        }
    }

    qsort(freqTable.table, freqTable.length, sizeof(WordInfo), compareFreqTableCells);


    while (freqTable.table[0].frequency == 0) {
        freqTable.table++;
        freqTable.length--;
    }

    return freqTable;
}

uint64_t getCompressedFileSizeBits(FreqTable *freqTable, ByteCode **codeTable) {
    uint64_t size = 0;

    for (int i = 0; i < freqTable->length; ++i) {
        WORD word = freqTable->table[i].word;
        size += codeTable[word]->length * freqTable->table[i].frequency;
    }

    return size;
}

Bitset *encodeFiles(ConcatedFile *file, FreqTable *freqTable, ByteCode **codeTable) {
    uint64_t compressedFileSizeBits = getCompressedFileSizeBits(freqTable, codeTable);

    Bitset *compressedFile = Bitset_new(compressedFileSizeBits);

    uint64_t cnt = 0;

    for (int k = 0; k < file->filesCount; ++k) {
        rewind(file->files[k]);

        for (uint64_t i = 0; i < file->fileSizeList[k]; ++i) {
            WORD buffer;
            fread(&buffer, sizeof(buffer), 1, file->files[k]);

            Bitset_writeBits(compressedFile, cnt, codeTable[buffer]->code, codeTable[buffer]->length);

            cnt += codeTable[buffer]->length;
        }

        fclose(file->files[k]);
    }

    return compressedFile;
}

void archive(char **filePathList, int filePathListLength, char *archivePath) {
    ConcatedFile *file = concatFiles(filePathList, filePathListLength);

    FreqTable freqTable = getFreqTable(file);

    HuffmanTreeNode *root = buildHuffmanTree(&freqTable);

    ByteCode **codeTable = calloc(WORD_CAPATCITY, sizeof(ByteCode *));

    buildCodeTable(root, codeTable, 0, 0);

    file->encodedHuffmanTree = encodeHuffmanTree(root);

    freeHuffmanTree(&root);

    file->compressedFile = encodeFiles(file, &freqTable, codeTable);

    free(codeTable);
    codeTable = NULL;

    createArchiveFile(archivePath, file);
}


