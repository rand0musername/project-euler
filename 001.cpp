// RandomUsername (Nikola Jovanovic)
// Project Euler
// 001

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

lld n, ret;

lld m(lld x)
{
    return (x+1) * x / 2;
}

int main()
{
    n = 1000;
    n--;
    ret = m(n/3) * 3 + m(n/5) * 5 - m(n/15) * 15;
    printf("%lld\n", ret);
    return 0;
}
