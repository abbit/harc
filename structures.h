//
// Created by Abbit on 06/06/2020.
//

#ifndef HARC_STRUCTURES_H
#define HARC_STRUCTURES_H

#include <stdio.h>
#include <stdint.h>

#include "settings.h"
#include "bitset.h"

typedef struct {
    uint32_t frequency;
    WORD word;
} WordInfo;

typedef struct {
    WordInfo *table;
    uint32_t length;
} FreqTable;

typedef struct {
    uint32_t code;
    uint8_t length;
} ByteCode;

typedef struct huffman_tree_node {
    WORD word;
    uint32_t frequency;
    struct huffman_tree_node *left;
    struct huffman_tree_node *right;
    struct huffman_tree_node *parent;
} HuffmanTreeNode;

typedef struct {
    FILE **files;
    uint64_t size;
    uint64_t *fileSizeList;
    char **fileNameList;
    uint32_t filesCount;
    Bitset *compressedFile;
    Bitset *encodedHuffmanTree;
    uint32_t crc32;
} ConcatedFile;

#endif //HARC_STRUCTURES_H
