//
// Created by Abbit on 04/06/2020.
//

#ifndef HARC_FILES_H
#define HARC_FILES_H

#include "structures.h"

off_t getFileSize(char *filePath);

ConcatedFile *concatFiles(char **filePathList, int filePathListLength);

void createArchiveFile(char *archivePath, ConcatedFile *file);

ConcatedFile *readCompressedFileHeader(char *archivePath);

ConcatedFile *readCompressedFile(char *archivePath);

#endif //HARC_FILES_H
