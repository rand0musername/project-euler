// RandomUsername (Nikola Jovanovic)
// Project Euler
// 005

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

lld lcm(lld a, lld b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    lld ret = 1;
    ff(i, 1, 20)
    {
        ret = lcm(ret, i);
    }
    printf("%lld\n", ret);
    return 0;
}
