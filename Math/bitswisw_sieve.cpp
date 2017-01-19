#include <bits/stdc++.h>

using namespace std;

#define M 100000
bool marked[M];
bool isPrime( int n ) {
  if( n < 2 ) return false;
  if( n == 2 ) return true;
  if( !(n&1) ) return false;
  return marked[n] == false;
}
void sieve( int n ) {
  for( int i = 3; i*i <= n; i += 2 )
    if( marked[i] == false )
      for( int j = i * i; j <= n; j += i + i )
        marked[j] = true;
}

#define M 100000
int marked[M/64+2];
#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x) marked[x/64] |= (1<<((x%64)/2))
void sieve( int n ) {
  for( int i = 3; i * i <= n; i += 2 )
    if(!on(i))
      for( int j = i * i; j <= n; j += i + i )
        mark(j);
}
bool isPrime( int n ) {
  return n > 1 && ( n == 2 || ((n&1) && !on(n)));
}

int main()
{
	sieve(100);
	for( int i = 0; i < 100; i++ ) cout << i << "-> " << isPrime(i) << endl;
}
