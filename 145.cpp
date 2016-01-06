// RandomUsername (Nikola Jovanovic)
// Project Euler
// 145

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(int i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 105

using namespace std;

int NB(int n);
int NS(int n);
int PB(int n);

int R(int n)
{
    if(n == 1) return 0;
    return 20*NB(n-2) + 20*PB(n-2);
}

int F()
{
    int ret = 0;
    ff(i, 1, 9)
    {
        ret += R(i);
    }
    return ret;
}


int rev(int n)
{
    queue<int> x;
    while(n > 0)
    {
        x.push(n%10);
        n /= 10;
    }
    while(!x.empty())
    {
        n*=10;
        n+=x.front();
        x.pop();
    }
    return n;
}

bool good(int n)
{
    while(n > 0)
    {
        if( ((n%10)%2) == 0 ) return false;
        n /= 10;
    }
    return true;
}

int main()
{
    printf("%d\n", F());
    return 0;
}

int NB(int n)
{
    if(n == 1) return 0;
    if(n == 0) return 1;
    return 30*NB(n-2);
}

int NS(int n)
{
    if(n == 1) return 0;
    if(n == 0) return 0;
    return 25*PB(n-2);
}

int PB(int n)
{
    if(n == 1) return 5;
    if(n == 0) return 0;
    return 20*NS(n-2);
}
