// @file array_functions.h

#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include "Rectangle.h"

void fill_random(int randomArray[], int size){
    for(int i = 0; i < size; i++){
        randomArray[i] = (rand() % 1000) + 1;
    }
}

double average(int randomArray[], int size){
    double average = 0;
    
    for(int i = 0; i < size; i++){
        average += randomArray[i];
    }
    
    average = average / size;
    
    return average;
}

void test(int randomArray[], int size){
    for(int i = 0; i < size; i++){
        cout << randomArray[i] << endl;
    }
}

void make_puzzle(char array[][15], int row){
    int column = 15;
    
    for(int r = 0; r < row; r++){
        for(int c = 0; c < column; c++){
            array[r][c] = static_cast<char>(rand() % 26 + 'a');
        }
    }
}

void print_puzzle(char array[][15], int row){
    int column = 15;
    
    for(int r = 0; r < row; r++){
        for(int c = 0; c < column; c++){
            cout << array[r][c] << " ";
        }
        
        cout << endl;
    }
}

void print_rectangles(Rectangle array[], int size){
    for(int i = 0; i < size; i++){
        cout << i << ": " << array[i].get_length() <<
        " x " << array[i].get_width() << endl;
    }
}

void random_rectangles(Rectangle array[], int size){
    for(int i = 0; i < size; i++){
        array[i].set_length((rand() % 100) + 1);
        array[i].set_width((rand() % 100) + 1);
    }
}

#endif