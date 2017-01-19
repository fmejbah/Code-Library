#include <stdio.h>

void InsertionSort( int A[], int n ) {
    int i, j, k;

    for( i = 1; i < n; i++ ) {
        j = i - 1;
        k = A[i];

        while( A[j] > k && j >= 0 ) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = k;
    }
}

int main() {
    int A[10], n, i;

    scanf("%d", &n);
    for( i = 0; i < n; i++ ) {
        scanf("%d", &A[i]);
    }

    InsertionSort(A,n);

    for( i = 0; i < n; i++ ) {
        printf("%d ", A[i]);
    }
}
