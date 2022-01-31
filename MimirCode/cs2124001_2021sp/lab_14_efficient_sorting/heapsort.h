// @ heapsort.h

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "maxheap.h"

void heap_sort(int array[], int size){
    make_max_heap_bottom_up(array, size);
    int elem_remain = size;
    while (elem_remain > 1)
        heap_remove(array, elem_remain);
}

#endif