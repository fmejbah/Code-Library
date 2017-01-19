#include <bits/stdc++.h>

using namespace std;

/*
 * a^b % M
 */
int bigMod( int a, int b, int M )
{
    if( b == 0 ) return 1 % M;
    int x = bigMod(a,b/2,M);
    x = (x * x) % M;
    if( b % 2 == 1 ) x = (x * a) % M;
    return x;
}

/*
 * a^n
 */
double pow( double a, int n )
{
    double r = 1;
    while(n)
    {
        if(n&1) r *= a;
        a *= a;
        n >>= 1;
    }
    return r;
}

/*
 * 1 + a + a^2 + a^3 + . . . . + a^(b-1) % M
 */
int bigSum( int a, int b, int M )
{
    if( b == 1 ) return 1 % M;
    int x = bigSum((a*a)%M,b/2,M);
    x = (x * (a + 1) ) % M;
    if(b&1) x = (1 + (a * x) % M) % M;
    return x;
}

int main()
{
    cout << bigMod(10,5,1007) << endl;
    cout << bigSum(10,5,1007) << endl;
}
