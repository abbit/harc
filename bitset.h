//
// Created by Abbit on 06/06/2020.
//

#ifndef HARC_BITSET_H
#define HARC_BITSET_H

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#include "settings.h"

typedef uint8_t bitword;

#define BITWORD_BITS (CHAR_BIT * sizeof(bitword))

typedef struct {
    bitword *arr;
    uint64_t arrLen;
    uint64_t bitsetLength;
} Bitset;

Bitset *Bitset_new(uint64_t length);

bool Bitset_get(const Bitset *bitset, uint64_t idx);

void Bitset_set(Bitset *bitset, uint64_t idx, bool newval);

void Bitset_writeWord(Bitset *bitset, uint64_t start, WORD word);

WORD Bitset_readWord(Bitset *bitset, uint64_t start);

void Bitset_writeBits(Bitset *bitset, uint64_t start, uint32_t word, uint8_t length);

uint64_t Bitset_convertBitsetLengthToArrLen(uint64_t bitsetLength);

#endif //HARC_BITSET_H
