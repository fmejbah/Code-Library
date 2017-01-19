#include <bits/stdc++.h>

using namespace std;

#define M 100000
int phi[1000005];
void sievephi() {
  for( int i = 0; i <= M; i++ )
    phi[i] = i;
  for( int i = 2; i <= M; i++ )
    if( phi[i] == i )	// i is prime
      for( int j = i; j <= M; j += i )
        phi[j] -= phi[j]/i;
}
int _phi( int n ) {
  int ret = n;
  for( int i = 2; i * i <= n; i++ ) {
    if( n % i == 0 ) {
      while( n % i == 0 ) n /= i;
      ret -= ret/i;
    }
  }
  if( n > 1 ) ret -= ret/n;
  return ret;
}

int main()
{
    sievephi();
    for( int i = 0; i <= 100; i++ )
        cout << i << " -> " << phi[i] << " " << _phi(i) << endl;
}
