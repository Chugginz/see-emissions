/**
 *******************************************************************************
 * @file    maxheap.h
 * @brief   A header file acting as a library, containing functions that conduct
 *          acts with the array and heapifying, sifting, etc.
 *
 * @author  Christian Huggins
 * @date    April 29th, 2021
 *******************************************************************************
**/

#ifndef MAXHEAP_H
#define MAXHEAP_H

/**
 * @brief       This function finds the left leaf of a given index
 *
 * @detailed    This function isn't templated due to the fact that we're dealing
 *              with indexes, so it uses the formula uses the formula to find
 *              the left leaf and returns that index.
 *              
 * @param       int i           the index of the root
 * 
 * @param       int size         the size of the array
 * 
 * @return      Returns the index of the left leaf
**/

int find_left_leaf(int i, int size);

/**
 * @brief       This function finds the right leaf of a given index
 *
 * @detailed    This function isn't templated due to the fact that we're dealing
 *              with indexes, so it uses the formula uses the formula to find
 *              the right leaf and returns that index.
 *              
 * @param       int i           the index of the root
 * 
 * @param       int size         the size of the array
 * 
 * @return      Returns the index of the right leaf
**/

int find_right_leaf(int i, int size);

/**
 * @brief       This function finds the parent leaf/root of a given index
 *
 * @detailed    This function isn't templated due to the fact that we're dealing
 *              with indexes, so it uses the formula uses the formula to find
 *              the parent leaf/root and returns that index.
 *              
 * @param       int i           the index of the leaf of the parent being 
 *                              looked for
 * 
 * @return      Returns the index of the parent
**/

int find_parent(int i);

/**
 * @brief       This function inserts an element into a max heap
 *
 * @detailed    This templated version of max heap insert adds a value
 *              into an array and then moves it to where it's needed to be
 *              
 * @param       T new_value      the value being added to the array
 * 
 * @param       T array[]        the array that is being added to
 * 
 * @param       int &size         the size of the array being passed by
 *                              reference due to the size changing
**/

template <typename T>
void max_heap_insert(T new_value, T array[], int &size);

/**
 * @brief       This function removes an element from a max heap
 *
 * @detailed    This templated version of max heap insert removes a value
 *              from an array and then reduces the size of the array by 1
 * 
 * @param       T array[]        the array that having an element removed
 * 
 * @param       int &size         the size of the array being passed by
 *                              reference due to the size changing
 * 
 * @return      Returns the element removed from the array
**/

template <typename T>
T heap_remove(T array[], int &size);

/**
 * @brief       This function sifts down an array
 *
 * @detailed    This templated version of max heap sift down sorts the max heap
 *              by sifting down the elements in the array using the other sift
 *              down function
 * 
 * @param       T array[]        the array that is being edited
 * 
 * @param       int &size         the size of the array being passed by
 *                              reference due to the size changing
 *
**/

template <typename T>
void max_heap_sift_down(T array[], int size);

/**
 * @brief       This function sifts down an array
 *
 * @detailed    This templated version of max heap sift down sorts the max heap
 *              by sifting down the elements in the array
 * 
 * @param       T array[]        the array that having an element removed
 * 
 * @param       int left         index of farhest left element, typically 0
 * 
 * @param       int right         the index of the farthest right element, aka
 *                                  the size - 1
**/

template <typename T>
void max_heap_sift_down(T array[], int left, int right);

/**
 * @brief       This function makes a max heap top down
 *
 * @detailed    This templated version of max heap top down creates a max heap
 *              using the top down method
 * 
 * @param       T array[]        the array that is being edited
 * 
 * @param       int size         the size of the array
**/

template <typename T>
void make_max_heap_top_down(T array[], int size);

/**
 * @brief       This function makes a max heap bottom up
 *
 * @detailed    This templated version of max heap bottom up creates a max heap
 *              using the bottom up method
 * 
 * @param       T array[]        the array that is being edited
 * 
 * @param       int size         the size of the array
**/

template <typename T>
void make_max_heap_bottom_up(T array[], int size);

int find_left_leaf(int i, int size){
    //formula to find the left leaf
    int left_leaf = 2 * i + 1;
    if (left_leaf > size - 1)
        left_leaf = i;
    
    return left_leaf;
}

int find_right_leaf(int i, int size){
    //formula to find the right leaf
    int right_leaf =  2 * i + 2;
    if (right_leaf > size - 1)
        right_leaf = i;
    
    return right_leaf;
}

int find_parent(int i){
    //formula to find the parent
    int parent = (i - 1) / 2;
    if (parent < 0)
        parent = i;
        
    return parent;
}

template <typename T>
void max_heap_insert(T new_value, T array[], int &size){
    //Initialize i to equal size
    int i = size;
    //Set the value at index i to that of the new value
    array[i] = new_value;
    //While is is greater than 0 and the value at the index of i is greather
    // than the value at the index of the parent of i
    while (i > 0 && array[i] > array[find_parent(i)]){
        //Swap the value at the index i and the value at the index of the
        // parent of i
        std::swap(array[i], array[find_parent(i)]);
        //Set i to be the parent of i
        i = find_parent(i);
    }
    //Increment size
    size++;
}

template <typename T>
T heap_remove(T array[], int &size){
    //Set the result to the first value in the array
    T result = array[0];
    //Swap the first value and the last
    std::swap(array[0], array[size - 1]);
    //Decrement size
    size--;
    //Sift down the heap
    max_heap_sift_down(array, size);
    
    return result;
}

template <typename T>
void max_heap_sift_down(T array[], int size){
    //Pass the left, the right, and the array to the other sift down function
    max_heap_sift_down(array, 0, size - 1);
}

template <typename T>
void max_heap_sift_down(T array[], int left, int right){
    //Initialize done to be false
    bool done = false;
    //Initialize i to be left
    int i = left;
    //While done is false and the left leaf is less than the right
    while (done == false && find_left_leaf(i, right) < right){
        //Initialize the max child to be the index of the left leaf
        int max_child = find_left_leaf(i, right);
        //If the right leaf index is less than right and the right leaf value
        // is greater than the left leaf value
        if (find_right_leaf(i, right) <= right 
            && array[find_right_leaf(i, right)] 
            > array[find_left_leaf(i, right)])
            //Set the max child to be the index of the right leaf
            max_child = find_right_leaf(i, right);
        //If the max child index value is greater than the i index value
        if (array[max_child] > array[i]){
            //Swap the two values
            std::swap(array[max_child], array[i]);
            //Set i to the max child index
            i = max_child;
        }
        else
            //Set done to be true
            done = true;
    }
}

template <typename T>
void make_max_heap_top_down(T array[], int size){
    //Initialize the heap size to 0
    int heap_size = 0;
    //While the heap size is less than the given size
    while (heap_size < size)
        //Call insert function given the value at the heap size indexed valued,
        // the array, and the heap size index
        max_heap_insert(array[heap_size], array, heap_size);
}

template <typename T>
void make_max_heap_bottom_up(T array[], int size){
    //Initialize subroot to the parent of the last index value
    int subroot = find_parent(size - 1);
    //While the subroot is greater than or equal to 0
    while (subroot >= 0){
        //Call the sift down function fiven the array, subroot, and the last
        // index
        max_heap_sift_down(array, subroot, size - 1);
        //Decrement the subroot
        subroot--;
    }
}

#endif