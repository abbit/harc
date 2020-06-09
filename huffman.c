//
// Created by Abbit on 05/06/2020.
//

#include <stdlib.h>
#include <stddef.h>

#include "huffman.h"
#include "heap.h"

HuffmanTreeNode *buildHuffmanTree(FreqTable *freqTable) {
    Heap *heap = Heap_new(freqTable->length);

    for (int i = 0; i < freqTable->length; i++) {
        HuffmanTreeNode *node = malloc(sizeof(HuffmanTreeNode));

        node->word = freqTable->table[i].word;
        node->frequency = freqTable->table[i].frequency;
        node->left = NULL;
        node->right = NULL;

        Heap_push(heap, node);
    }

    while (heap->size != 1) {
        HuffmanTreeNode *left = Heap_pop(heap);
        HuffmanTreeNode *right = Heap_pop(heap);

        HuffmanTreeNode *root = malloc(sizeof(HuffmanTreeNode));

        root->left = left;
        root->right = right;
        root->frequency = left->frequency + right->frequency;

        Heap_push(heap, root);
    }

    HuffmanTreeNode *root = Heap_pop(heap);

    free(heap);

    return root;
}

bool isLeaf(HuffmanTreeNode *node) {
    if (node->left == NULL && node->right == NULL) {
        return true;
    }
    return false;
}

void buildCodeTable(HuffmanTreeNode *root, ByteCode **codeTable, uint32_t code, uint8_t length) {
    if (isLeaf(root)) {
        codeTable[root->word] = malloc(sizeof(ByteCode));
        codeTable[root->word]->code = code;
        codeTable[root->word]->length = length;

        return;
    }

    uint64_t leftCode = code | (0 << length);
    uint64_t rightCode = code | (1 << length);
    buildCodeTable(root->left, codeTable, leftCode, length + 1);
    buildCodeTable(root->right, codeTable, rightCode, length + 1);
}

void countEncodedHuffmanTreeLen(HuffmanTreeNode *root, uint16_t *count) {
    (*count)++;

    if (isLeaf(root)) {
        (*count) += CHAR_BIT;
        return;
    }

    countEncodedHuffmanTreeLen(root->left, count);
    countEncodedHuffmanTreeLen(root->right, count);
}

void HuffmanTreeNode_encode(HuffmanTreeNode *node, Bitset *bitset, uint64_t *currPos) {
    if (isLeaf(node)) {
        Bitset_set(bitset, *currPos, 1);
        (*currPos)++;
        Bitset_writeWord(bitset, *currPos, node->word);
        (*currPos) += sizeof(node->word) * CHAR_BIT;
    } else {
        Bitset_set(bitset, *currPos, 0);
        (*currPos)++;
        HuffmanTreeNode_encode(node->left, bitset, currPos);
        HuffmanTreeNode_encode(node->right, bitset, currPos);
    }
}

void HuffmanTreeNode_decode(HuffmanTreeNode *parent, Bitset *encodedHuffmanTree, uint64_t *currPos) {
    if (encodedHuffmanTree->bitsetLength == *currPos) {
        return;
    }

    if (parent->left != NULL && parent->right != NULL) {
        HuffmanTreeNode_decode(parent->parent, encodedHuffmanTree, currPos);
        return;
    }

    HuffmanTreeNode *node = malloc(sizeof(HuffmanTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    if (parent->left == NULL) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    bool val = Bitset_get(encodedHuffmanTree, *currPos);
    (*currPos)++;

    if (val) {
        node->word = Bitset_readWord(encodedHuffmanTree, *currPos);
        (*currPos) += sizeof(WORD) * CHAR_BIT;
        HuffmanTreeNode_decode(parent, encodedHuffmanTree, currPos);
    } else {
        HuffmanTreeNode_decode(node, encodedHuffmanTree, currPos);
    }
}

Bitset *encodeHuffmanTree(HuffmanTreeNode *root) {
    uint16_t encodedHuffmanTreeLen = 0;
    countEncodedHuffmanTreeLen(root, &encodedHuffmanTreeLen);

    Bitset *encodedHuffmanTree = Bitset_new(encodedHuffmanTreeLen);

    uint64_t currPos = 0;
    HuffmanTreeNode_encode(root, encodedHuffmanTree, &currPos);

    return encodedHuffmanTree;
}

HuffmanTreeNode *decodeHuffmanTree(Bitset *encodedHuffmanTree) {
    HuffmanTreeNode *root = malloc(sizeof(HuffmanTreeNode));
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    root->frequency = 322;

    uint64_t currPos = 1;
    HuffmanTreeNode_decode(root, encodedHuffmanTree, &currPos);

    return root;
}

WORD getNextWord(HuffmanTreeNode *root, Bitset *bitset, uint64_t *pos) {
    HuffmanTreeNode *head = root;

    while (!isLeaf(head)) {
        bool val = Bitset_get(bitset, *pos);

        if (val) {
            head = head->right;
        } else {
            head = head->left;
        }

        (*pos)++;
    }

    return head->word;
}
