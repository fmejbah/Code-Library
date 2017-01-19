#include <bits/stdc++.h>

using namespace std;
/*
 * A[] -> a sorted array
 * low -> starting index of array
 * high -> last index of array
 * x -> if x is found in array return x's index else return -1
 */
int BinarySearch( int A[], int low, int high, int x )
{
    if( low > high ) return -1;
    int mid = (low+high)/2;
    if( x == A[mid] ) return mid; // Found x, exit
    else if( x < A[mid] ) BinarySearch(A,low,mid-1,x);
    else BinarySearch(A,mid-1,high,x);=
}
