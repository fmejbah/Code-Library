/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * Data Structures: Heap                                #
 * Date: 11/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

class heap {
  int *A, N;
  public:
  heap( int n = 100 ) {
    A = new int[n];
    N = 0;
  }
  bool isEmpty() {
    return N == 0;
  }
  int size() {
    return N;
  }
  void swim( int k ) {
    while( k > 1 && A[k] > A[k/2] ) {
      swap(A[k],A[k/2]);
      k = k/2;
    }
  }
  void insert( int x ) {
    A[++N] = x;
    swim(N);
  }
  void sink( int k ) {
    while( 2*k <= N ) { int j = 2*k;
      if( j < N && A[j] < A[j+1] ) j++;
      if( A[k] > A[j] ) break;
      swap(A[k], A[j]);
      k = j;
    }
  }
  int delMax() {
    int max = A[1];
    swap(A[1],A[N--]);
    A[N+1] = -1;
    sink(1);
    return max;
  }
};

void HeapSort( int *A, int n ) {
  for( int k = n/2; k >= 1; k-- )
    sink(k);    //Need to amplement
  while( n > 1 ) {
    swap(A[1],A[n--]);
    sink(1);    //Need to amplement
  }
}

int main() {
  heap h;
  return 0;
}
