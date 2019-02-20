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
    printf("We running boi\n");
}



