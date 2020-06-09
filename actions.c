//
// Created by Abbit on 04/06/2020.
//

#include "structures.h"
#include "files.h"
#include "actions.h"

void deleteFiles(char *archivePath) {}

void getActhiveInfo(char *archivePath) {
    ConcatedFile *file = readCompressedFileHeader(archivePath);

    printf("\nArchive consists of %u files\n\n", file->filesCount);

    for (uint32_t i = 0; i < file->filesCount; ++i) {
        printf("#%u:\n", i+1);
        printf("    Name: %s\n", file->fileNameList[i]);
        printf("    Size: %llu bytes\n", file->fileSizeList[i]);
    }
}

void validateArchive(char *archivePath) {}