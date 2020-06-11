//
// Created by Abbit on 05/06/2020.
//

#ifndef HARC_HUFFMAN_H
#define HARC_HUFFMAN_H

#include "structures.h"
#include "bitset.h"

HuffmanTreeNode *buildHuffmanTree(FreqTable *freqTable);

void buildCodeTable(HuffmanTreeNode *root, ByteCode **codeTable, uint32_t code, uint8_t length);

void countEncodedHuffmanTreeLen(HuffmanTreeNode *root, uint16_t *count);

Bitset *encodeHuffmanTree(HuffmanTreeNode *root);

HuffmanTreeNode *decodeHuffmanTree(Bitset *encodedHuffmanTree);

WORD getNextWord(HuffmanTreeNode *root, Bitset *bitset, uint64_t *pos);

void freeHuffmanTree(HuffmanTreeNode **root);

#endif //HARC_HUFFMAN_H
