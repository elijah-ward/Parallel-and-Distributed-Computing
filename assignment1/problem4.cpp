/**
 * Assignment #1: Problem #4
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <algorithm>
#include <limits>

#define MATRIX_N 16

void recurse_stencil(int *A, int *D, int n, int blocksize, int imin, int imax, int jmin, int jmax) {

    int di = imax - imin;
    int dj = jmax - jmin;

    if (di >= dj && di >= blocksize) {
        int mi = imin + di / 2;
        cilk_spawn recurse_stencil(A, D, n, blocksize, imin, mi, jmin, jmax);
            recurse_stencil(A, D, n, blocksize, mi, imax, jmin, jmax);
        cilk_sync;
    } else if (dj >= blocksize) {
        int mj = jmin + dj / 2;
        cilk_spawn recurse_stencil(A, D, n, blocksize, imin, imax, jmin, mj);
            recurse_stencil(A, D, n, blocksize, imin, imax, mj, jmax);
        cilk_sync;

    } else {
        for ( int i = imin; i < imax; i++ ) {
            for ( int j = jmin; j < jmax; j++) {
                if ( i != n && i != 0 && j != n && j != 0){
                    D[i*jmax + j] = 0.25*(A[(i-1)*jmax + j] + A[(i*jmax) + j - 1] + A[(i+1)*jmax + j] + A[(i*jmax) + j+1]);
                }
            }
        }
    }
}

void divide_conquer_stencil(int *A, int n, int blocksize) {

    int *D = new int[n*n];

    for ( int i=0; i<n*n; i++ ) {
        D[i] = 0;
    }

    recurse_stencil(A, D, n, blocksize, 0, n, 0, n );

    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {
            A[i*n + j] = D[i*n + j];
        }
    }
}

int main() {

    int n = MATRIX_N;
    int s = n*n;
    int blocksize = 2;
    int *A = new int[s];

    srand(time(NULL));

    printf("Creating random matrix...\n\n");
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {
            A[i*n + j] = rand() % 100;
            printf("%d ", A[i*n + j]);
        }
        puts("\n\n");
    }

    divide_conquer_stencil(A, n, blocksize);

    puts("\n\n====================================================================================\n\n");


    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {
            printf("%d ", A[i*n + j]);
        }
        puts("\n\n");
    }

}


