/* Write a program to check whether a given square matrix is an Identity Matrix.
An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int A[n][n];

    // Read matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int isIdentity = 1;

    // Check identity conditions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && A[i][j] != 1)
                isIdentity = 0;
            if (i != j && A[i][j] != 0)
                isIdentity = 0;
        }
    }

    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
