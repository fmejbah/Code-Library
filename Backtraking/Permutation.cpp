#include <bits/stdc++.h>

using namespace std;

int n = 3, ary[] = {1, 2, 3};
vector<int> result;
bool taken[3] = {0};

void permutation()
{
    if( result.size() == n )
    {
        for( int i = 0; i < n; i++ )
            cout << result[i] << " ";
        puts("");
        return;
    }

    for( int i = 0; i < n; i++ )
    {
        if( taken[i] == 0 )
        {
            taken[i] = 1;
            result.push_back(ary[i]);
            permutation();
            taken[i] = 0;
            result.pop_back();
        }
    }
}

void permutation( char str[], int i, int n )
{
    if( i == n )
    {
        cout << str << endl;
        return;
    }
    for( int j = i; j <= n; j++ )
    {
        swap(str[i],str[j]);
        permutation(str,i+1,n);
        swap(str[i],str[j]);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    permutation();
    char s[] = "ABC";
    permutation(s,0,2);
}

/*
int n;
char s[100];
bool taken[100] = {0};
vector <char> result;
void permutation() {
    if( result.size() == n ) {
        for( int i = 0; i < n; i++ )
            printf("%c ", result[i]);
        printf("\n");
        return;
    }
    for( int i = 0; i < n; i++ ) {
        if( taken[i] == 0 ) {
            taken[i] = 1;
            result.push_back(s[i]);
            permutation();
            taken[i] = 0;
            result.pop_back();
        }
    }
}
*/
