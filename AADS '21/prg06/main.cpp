/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Main file for operating homework 6
 *
 * @remarks
 *      Course:        Algorithms & Advanced Data Structures
 *      Due Date:      11/04/2021
 *      Instructor:    Hung-Chi Su
 *
 * @author  Christian Huggins
 * @date    November 4th, 2021
 *******************************************************************************
**/

   #include <iostream>
      using std::cout;
      using std::endl;
      using std::flush;
      using std::ostream;
      using std::cin;

void merge(int A[], int B[], int C[], int nA, int nB, int nC);

int main (void)
{

   int A[] = {5,10,20,27,29,36,42,43,47,48};
   int B[] = {15,30,32,37,39,56,62,63,71,82};
   int C[20] = {0};

   //print array A
   cout << "A:\n";
   for (int i=0; i<10; i++)
      cout << A[i] << " ";

   //print array B
   cout << "\n\nB:\n";
   for (int i=0; i<10; i++)
      cout << B[i] << " ";

   //merge
   merge(A,B,C, 10,10,20);

   //print array C after merged
   cout << "\n\nC: (after merged):\n";
   for (int i=0; i<20; i++)
      cout << C[i] << " ";

   return 0;
}

//to merge two sorted arrays (B and C) into the 3rd array C
//input: 3 arrays, A, B, C, and their respective sizes, nA, nB, nC
//assume array C is large enough to hold A and B and all nA,nB,nC are properly initialized
void merge(int A[], int B[], int C[], int nA, int nB, int nC)
{
    // Initialize counter
    int counter = 0;
    // While the counter is going through array A
    while (counter < nA){
        // Store each value at the alloted index value
        C[counter] = A[counter];
        counter++;
    }

    // While the counter is going through array B
    for (int i = 0; i < nB; i++){
        // Set C at the next location to B at the loop counter
        C[counter] = B[i];
        // Iterate counter
        counter++;
    }
    
    // While the counter is less than the size of the array C
    for (int i = 0; i < nC; i++){
        // And while the iterating counter is less than the size of the array C
        for (int j = i; j < nC; j++){
            // If the value at index i is greater than the one at index j
            if (C[i] > C[j]){
                // Initialize a value to store the value at index i
                int value = C[i];
                // Set the value at index i to the value at index j
                C[i] = C[j];
                // Set the value at index j to the value at index i thats stored
                C[j] = value;
            }
        }
    }

}