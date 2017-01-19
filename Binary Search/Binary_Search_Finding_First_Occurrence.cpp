#include <bits/stdc++.h>

using namespace std;

int BinarySearchFirstOccurrence( int A[], int n, int x )
{
    int low = 0, high = n-1, result = -1;
    while( low <= high )
    {
        int mid = (low+high)/2;
        if( x == A[mid] )
        {
            result = mid;
            high = mid - 1;
        }
        else if( x < A[mid] ) high = mid - 1;
        else low = mid + 1;
    }
    return result;
}
