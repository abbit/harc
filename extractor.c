//
// Created by Abbit on 04/06/2020.
//

#include "extractor.h"
#include "structures.h"
#include "files.h"
#include "huffman.h"

void decodeFile(ConcatedFile *file) {
    HuffmanTreeNode *huffmanTree = decodeHuffmanTree(file->encodedHuffmanTree);

    uint64_t pos = 0;

    for (uint32_t i = 0; i < file->filesCount; ++i) {
        FILE *f = fopen(file->fileNameList[i], "wb");

        uint64_t size = 0;

        while (size < file->fileSizeList[i]) {
            WORD word = getNextWord(huffmanTree, file->compressedFile, &pos);

            fwrite(&word, sizeof(WORD), 1, f);

            size++;
        }

        fclose(f);
    }
}

void extract(char *archivePath) {
    ConcatedFile *file = readCompressedFile(archivePath);

    decodeFile(file);
}