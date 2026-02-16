/*You are given a rectangular matrix of integers.
Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.*/
#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int A[r][c];

    // Read matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // Top row
        for (int j = left; j <= right; j++)
            printf("%d ", A[top][j]);
        top++;

        // Right column
        for (int i = top; i <= bottom; i++)
            printf("%d ", A[i][right]);
        right--;

        // Bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", A[bottom][j]);
            bottom--;
        }

        // Left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", A[i][left]);
            left++;
        }
    }

    return 0;
}
