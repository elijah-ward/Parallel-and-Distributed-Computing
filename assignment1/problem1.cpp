/**
 * Assignment #1: Problem #1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <algorithm>

void add_sub_array(int* A, int* B, int* D, int i, int j) {
    for (int k=i; k<j; ++k) {
        D[k] = A[k] + B[k];
    }
}

void sum_array(int* A, int* B, int* D, int n) {
    int grain_size = 1;
    int r = std::ceil((float) n/grain_size);

    for (int k=0; k<r; ++k) {
        cilk_spawn(add_sub_array(A,B,D,
            k*grain_size,
            std::min((k+1)*grain_size,n))
        );
    }
    cilk_sync;
}

int main() {
    int n = 20;
    int numbers_1[n];
    int numbers_2[n];
    int sum[n];

    srand(time(NULL));

    for ( int i = 0; i < n; i++ )
    {
        int num1 = rand() % n;
        numbers_1[i] = num1;

        int num2 = rand() % n;
        numbers_2[i] = num2;
    }

    sum_array(numbers_1, numbers_2, sum, n);

    for ( int i = 0; i < n; i++ )
    {
        printf("numbers_1 at i: %d is %d\nnumbers_2 at i: %d is %d\nsum at i: %d is %d\n\n",i, numbers_1[i], i, numbers_2[i], i, sum[i]);
    }
}



