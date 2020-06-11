//
// Created by Abbit on 04/06/2020.
//

#include "structures.h"
#include "files.h"
#include "actions.h"
#include "files.h"

void deleteFiles(char *archivePath) {}

void getActhiveInfo(char *archivePath) {
    ConcatedFile *file = readCompressedFileHeader(archivePath);

    uint64_t archSize = getFileSize(archivePath);

    double compressionRatio = (double)file->size / (double)archSize;

    printf("\nArchive consists of %u files\n", file->filesCount);
    printf("Сompression ratio: %.5lf\n\n", compressionRatio);

    for (uint32_t i = 0; i < file->filesCount; ++i) {
        printf("#%u:\n", i+1);
        printf("    Name: %s\n", file->fileNameList[i]);
        printf("    Size: %llu bytes\n", file->fileSizeList[i]);
    }
}

void validateArchive(char *archivePath) {
    uint32_t crcFromFile = readCRC32FromFile(archivePath);
    uint32_t calcedCrc = getCRC32FromFile(archivePath);

    if (crcFromFile == calcedCrc) {
        printf("Archive is ok\n");
    } else {
        printf("Archive is corrupted\n");
    }
}