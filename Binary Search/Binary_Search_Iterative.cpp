#include <bits/stdc++.h>

using namespace std;
/*
 * A[] -> a sorted array
 * n -> size of array
 * x -> if x is found in array return x's index else return -1
 */
int BinarySearch( int A[], int n, int x )
{
    int low = 0, high = n-1;
    while( low <= high )
    {
        int mid = (low+high)/2;
        if( x == A[mid] ) return mid; // Found x, exit
        else if( x < A[mid] ) high = mid-1;
        else low = mid+1;
    }
    return -1;      // x not found return -1
}
