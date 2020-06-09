//
// Created by Abbit on 06/06/2020.
//

#include "bitset.h"

#include <stdlib.h>
#include <string.h>
#include <limits.h>

uint64_t Bitset_getArrLen(uint64_t bitsetLength) {
    return ((bitsetLength + BITWORD_BITS - 1) / BITWORD_BITS) * sizeof(bitword);
}

Bitset *Bitset_new(uint64_t length) {
    Bitset *bitset = malloc(sizeof(Bitset));
    bitset->bitsetLength = length;
    bitset->arrLen = Bitset_getArrLen(length);

    bitset->arr = malloc(bitset->arrLen);
    memset(bitset->arr, 0, bitset->arrLen);

    return bitset;
}

bool Bitset_get(const Bitset *bitset, uint64_t idx) {
    if (bitset->arr[idx / BITWORD_BITS] & (1u << (BITWORD_BITS - 1 - (idx % BITWORD_BITS)))) {
        return true;
    }

    return false;
}

void Bitset_set(Bitset *bitset, uint64_t idx, bool newval) {
    if (newval) {
        bitset->arr[idx / BITWORD_BITS] |= 1u << (BITWORD_BITS - 1u - (idx % BITWORD_BITS));
    } else {
        bitset->arr[idx / BITWORD_BITS] &= ~(1u << (BITWORD_BITS - 1u - (idx % BITWORD_BITS)));
    }
}

void Bitset_writeWord(Bitset *bitset, uint64_t start, WORD word) {
    int wordLen = sizeof(word) * CHAR_BIT;

    for (int i = 0; i < wordLen; ++i) {
        bool val = (word >> (wordLen - i - 1)) & 1;
        Bitset_set(bitset, start + i, val);
    }
}

WORD Bitset_readWord(Bitset *bitset, uint64_t start) {
    WORD word = 0;

    int wordLen = sizeof(word) * CHAR_BIT;

    for (int i = 0; i < wordLen; ++i) {
        bool val = Bitset_get(bitset, start + i);

        word = (word << 1) | val;
    }

    return word;
}

void Bitset_writeBits(Bitset *bitset, uint64_t start, uint32_t word, uint8_t length) {
    for (uint8_t i = 0; i < length; ++i) {
        bool val = (word >> i) & 1;
        Bitset_set(bitset, start + i, val);
    }
}

