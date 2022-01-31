// @file array_functions.h

#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include "Rectangle.h"

void fill_random(int array[], int size){
    for (int i = 0; i < size; i++){
        array[i] = rand() % 1000 + 1;
    }
}

double average(int array[], int size){
    double average = 0;
    
    for (int i = 0; i < size; i++){
        average += array[i];
    }
    
    average = average / size;
    
    return average;
}

void make_puzzle(char array[][15], int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 15; j++){
            array[i][j] = static_cast<char>(rand() % 26 + 'a');
        }
    }
}

void print_puzzle(char array[][15], int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 15; j++){
            if (j != 14)
                cout << array[i][j] << " ";
            else
                cout  << array[i][j] << "\n";
        }
    }
}

void random_rectangles(Rectangle array[], int size){
    for (int i = 0; i < size; i++){
        array[i].set_length(rand() % 100 + 1);
        array[i].set_width(rand() % 100 + 1);
    }
}

void print_rectangles(Rectangle array[], int size){
    for (int i = 0; i < size; i++){
        cout << (i + 1) << ": " << array[i].get_length() << " x " 
        << array[i].get_width() << "\n";
    }
}

#endif