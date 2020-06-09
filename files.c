//
// Created by Abbit on 04/06/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

#include <sys/stat.h>

#include "files.h"


ConcatedFile *ConcatedFile_new(int filePathListLength) {
    ConcatedFile *file = malloc(sizeof(ConcatedFile));
    file->filesCount = filePathListLength;
    file->size = 0;
    file->fileSizeList = calloc(file->filesCount, sizeof(uint64_t));
    file->fileNameList = calloc(file->filesCount, sizeof(char *));
    file->files = calloc(file->filesCount, sizeof(FILE *));;
    file->compressedFile = NULL;
    file->encodedHuffmanTree = NULL;

    return file;
}

void ConcatedFile_add(ConcatedFile *file, char *filePath, uint32_t pos) {
    uint64_t fileSize = getFileSize(filePath);
    file->size += fileSize;
    file->fileSizeList[pos] = fileSize;

    char *fileName = basename(filePath);
    file->fileNameList[pos] = malloc(strlen(fileName));
    strncpy(file->fileNameList[pos], basename(filePath), strlen(fileName));
    file->files[pos] = fopen(filePath, "rb");
}

off_t getFileSize(char *filePath) {
    struct stat st;
    stat(filePath, &st);
    off_t fileSize = st.st_size;

    return fileSize;
}

ConcatedFile *concatFiles(char **filePathList, int filePathListLength) {
    ConcatedFile *file = ConcatedFile_new(filePathListLength);

    for (int i = 0; i < filePathListLength; ++i) {
        char *filePath = filePathList[i];

        ConcatedFile_add(file, filePath, i);
    }

    return file;
}

void createArchiveFile(char *archivePath, ConcatedFile *file) {
    FILE *archiveFile = fopen(archivePath, "wb");

    // write archive header
    fwrite(&file->encodedHuffmanTree->bitsetLength, sizeof(uint64_t), 1, archiveFile);
    fwrite(file->encodedHuffmanTree->arr, sizeof(bitword), file->encodedHuffmanTree->arrLen, archiveFile);
    fwrite(&file->filesCount, sizeof(uint32_t), 1, archiveFile);

    for (uint32_t i = 0; i < file->filesCount; ++i) {
        fwrite(&file->fileSizeList[i], sizeof(uint64_t), 1, archiveFile);

        size_t fileNameLen = strlen(file->fileNameList[i]);
        fwrite(&fileNameLen, sizeof(size_t), 1, archiveFile);

        fwrite(file->fileNameList[i], sizeof(char), fileNameLen, archiveFile);
    }

    fwrite(&file->compressedFile->bitsetLength, sizeof(uint64_t), 1, archiveFile);
    fwrite(file->compressedFile->arr, sizeof(bitword), file->compressedFile->arrLen, archiveFile);

    fclose(archiveFile);
}

ConcatedFile *readCompressedFile(char *archivePath) {
    FILE *archiveFile = fopen(archivePath, "rb");

    // read archive header
    uint64_t encodedHuffmanTreeLength;
    fread(&encodedHuffmanTreeLength, sizeof(uint64_t), 1, archiveFile);

    Bitset *encodedHuffmanTree = Bitset_new(encodedHuffmanTreeLength);

    fread(encodedHuffmanTree->arr, sizeof(bitword), encodedHuffmanTree->arrLen, archiveFile);

    uint32_t filesCount;
    fread(&filesCount, sizeof(uint32_t), 1, archiveFile);

    ConcatedFile *file = ConcatedFile_new(filesCount);
    file->encodedHuffmanTree = encodedHuffmanTree;

    for (int i = 0; i < file->filesCount; ++i) {
        fread(&file->fileSizeList[i], sizeof(uint64_t), 1, archiveFile);

        size_t fileNameLen;
        fread(&fileNameLen, sizeof(size_t), 1, archiveFile);
        file->fileNameList[i] = calloc(fileNameLen, sizeof(char));


        fread(file->fileNameList[i], sizeof(char), fileNameLen, archiveFile);
    }

    uint64_t compressedFileLength;
    fread(&compressedFileLength, sizeof(uint64_t), 1, archiveFile);

    file->compressedFile = Bitset_new(compressedFileLength);
    fread(file->compressedFile->arr, sizeof(bitword), file->compressedFile->arrLen, archiveFile);

    fclose(archiveFile);

    return file;
}
