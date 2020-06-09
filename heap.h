//
// Created by Abbit on 05/06/2020.
//

#ifndef HARC_HEAP_H
#define HARC_HEAP_H

#include <stdbool.h>
#include <stdint.h>

#include "structures.h"

typedef struct {
    uint16_t size;
    uint16_t max_size;
    HuffmanTreeNode **arr;
} Heap;

Heap *Heap_new(uint16_t max_elems);

void Heap_push(Heap *heap, HuffmanTreeNode *val);

HuffmanTreeNode *Heap_pop(Heap *heap);

bool Heap_isEmpty(Heap *heap);

#endif //HARC_HEAP_H
