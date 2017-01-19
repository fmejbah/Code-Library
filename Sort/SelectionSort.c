#include <stdio.h>

int loc, m;

void min( int A[], int k, int n ) {
    m = A[k];
    loc = k;
    k++;
    while(k<n) {
        if( A[k] < m ) {
            m = A[k];
            loc = k;
        }
        k++;
    }
}

void SelectionSort( int A[], int n ) {
    int i, t;
    for( i = 0; i < n-1; i++ ) {
        min(A,i,n);
        t = A[i];
        A[i] = m;
        A[loc] = t;
    }
}

int main() {
    int A[10], n, i;

    scanf("%d", &n);
    for( i = 0; i < n; i++ ) {
        scanf("%d", &A[i]);
    }

    SelectionSort(A,n);

    for( i = 0; i < n; i++ ) {
        printf("%d ", A[i]);
    }
}
