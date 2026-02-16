/*Write a program to check whether a given matrix is symmetric.
A matrix is said to be symmetric if it is a square matrix and is equal to its
transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).*/
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Read matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Check if square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int symmetric = 1;

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric)
            break;
    }

    if (symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
