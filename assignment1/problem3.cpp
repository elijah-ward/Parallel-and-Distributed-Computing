/**
 * Assignment #1: Problem #3
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <algorithm>
#include <limits>

#define GRAPH_SIZE 4

void floyd_all_pairs_parallel(int *D, int n) {
    for ( int k = 0; k < n; k++ ) {
        cilk_for ( int i = 0; i < n; i++ ) {
            cilk_for ( int j = 0; j < n; j++ ) {
                if (D[i*n + j] > D[i*n + k] + D[k*n + j]) {
                    D[i*n + j] = D[i*n + k] + D[k*n + j];
                }
            }
        }
    }
}

int main() {

    int n = GRAPH_SIZE;
    int INT_MAX = std::numeric_limits<int>::max();
    int adjacency_matrix[GRAPH_SIZE][GRAPH_SIZE] = {{0, INT_MAX, 1, INT_MAX}, {4, 0, 3, INT_MAX}, {INT_MAX, INT_MAX, 0, 2}, {INT_MAX, -1, INT_MAX, 0}};
    int *ptr = &adjacency_matrix[0][0];
    puts("BEFORE FW:\n");
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf("%d\t", adjacency_matrix[i][j]);
        }
        puts("\n");
    }
    puts("\n");


    floyd_all_pairs_parallel(ptr, n);

    puts("AFTER FW:\n");
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf("%d\t", adjacency_matrix[i][j]);
        }
        puts("\n");
    }

}



