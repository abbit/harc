//
// Created by Abbit on 05/06/2020.
//

#include "heap.h"

#include <stdlib.h>

void swap(HuffmanTreeNode **a, HuffmanTreeNode **b) {
    HuffmanTreeNode *tmp = *a;
    *a = *b;
    *b = tmp;
}

uint16_t Heap_getParentIndex(uint16_t idx) {
    return (idx - 1) / 2;
}

uint16_t Heap_getLeftLeafIndex(uint16_t idx) {
    return 2 * idx + 1;
}

uint16_t Heap_getRightLeafIndex(uint16_t idx) {
    return 2 * idx + 2;
}

void Heap_siftUp(Heap *heap, uint16_t idx) {
    if (idx == 0) {
        return;
    }

    uint16_t parentIdx = Heap_getParentIndex(idx);

    if (heap->arr[idx]->frequency < heap->arr[parentIdx]->frequency) {
        swap(&heap->arr[idx], &heap->arr[parentIdx]);
        Heap_siftUp(heap, parentIdx);
    }
}

void Heap_siftDown(Heap *heap, uint16_t idx) {
    uint16_t leftLeafIdx = Heap_getLeftLeafIndex(idx);
    uint16_t rightLeafIdx = Heap_getRightLeafIndex(idx);

    uint16_t smallestElIdx = idx;

    if (leftLeafIdx < heap->size && heap->arr[leftLeafIdx]->frequency < heap->arr[smallestElIdx]->frequency) {
        smallestElIdx = leftLeafIdx;
    }
    if (rightLeafIdx < heap->size && heap->arr[rightLeafIdx]->frequency < heap->arr[smallestElIdx]->frequency) {
        smallestElIdx = rightLeafIdx;
    }

    if (smallestElIdx != idx) {
        swap(&heap->arr[smallestElIdx], &heap->arr[idx]);
        Heap_siftDown(heap, smallestElIdx);
    }
}


Heap *Heap_new(uint16_t max_elems) {
    Heap *h = (Heap *) malloc(sizeof(Heap));
    h->max_size = max_elems;
    h->size = 0;
    h->arr = (HuffmanTreeNode **) calloc(max_elems, sizeof(HuffmanTreeNode *));

    return h;
}

bool Heap_isEmpty(Heap *heap) {
    if (heap->size) {
        return false;
    }

    return true;
}

void Heap_push(Heap *heap, HuffmanTreeNode *val) {
    heap->arr[heap->size] = val;
    Heap_siftUp(heap, heap->size);
    heap->size++;
}

HuffmanTreeNode *Heap_pop(Heap *heap) {
    HuffmanTreeNode *res = heap->arr[0];
    heap->size--;
    swap(&heap->arr[0], &heap->arr[heap->size]);
    Heap_siftDown(heap, 0);

    return res;
}