// @ maxheap.h

#ifndef MAXHEAP_H
#define MAXHEAP_H

int find_left_leaf(int i, int size);

int find_right_leaf(int i, int size);

int find_parent(int i);

void max_heap_insert(int new_value, int array[], int &size);

int heap_remove(int array[], int &size);

void max_heap_sift_down(int array[], int &size);

void max_heap_sift_down(int array[], int left, int right);

void make_max_heap_top_down(int array[], int size);

void make_max_heap_bottom_up(int array[], int size);

int find_left_leaf(int i, int size){
    int left_leaf = 2 * i + 1;
    if (left_leaf > size - 1)
        left_leaf = i;
    
    return left_leaf;
}

int find_right_leaf(int i, int size){
    int right_leaf =  2 * i + 2;
    if (right_leaf > size - 1)
        right_leaf = i;
    
    return right_leaf;
}

int find_parent(int i){
    int parent = (i - 1) / 2;
    if (parent < 0)
        parent = i;
        
    return parent;
}

void max_heap_insert(int new_value, int array[], int &size){
    int i = size;
    array[size] = new_value;
    while (i > 0 && array[i] > array[find_parent(i)]){
        std::swap(array[i], array[find_parent(i)]);
        i = find_parent(i);
    }
    size++;
}

int heap_remove(int array[], int &size){
    int result = array[0];
    std::swap(array[0], array[size - 1]);
    size--;
    max_heap_sift_down(array, size);
    
    return result;
}

void max_heap_sift_down(int array[], int &size){
    max_heap_sift_down(array, 0, size);
}

void max_heap_sift_down(int array[], int left, int right){
    bool done = false;
    int i = left;
    while (done == false && find_left_leaf(i, right) <= right){
        int max_child = find_left_leaf(i, right);
        if (find_right_leaf(i, right) <= right 
            && array[find_right_leaf(i, right)] > array[find_left_leaf(i, right)])
            max_child = find_right_leaf(i, right);
        if (array[max_child] > array[i]){
            std::swap(array[max_child], array[i]);
            i = max_child;
        }
        else
            done = true;
    }
}

void make_max_heap_top_down(int array[], int size){
    int heap_size = 0;
    while (heap_size < size)
        max_heap_insert(array[heap_size], array, heap_size);
}

void make_max_heap_bottom_up(int array[], int size){
    int subroot = find_parent(array[size - 1]);
    while (subroot > 0){
        max_heap_sift_down(array, subroot, size - 1);
        subroot--;
    }
}

#endif