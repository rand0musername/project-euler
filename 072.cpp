// RandomUsername (Nikola Jovanovic)
// Project Euler
// 072

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(lld i=a; i<=b; i++)
#define fb(i,a,b) for(lld i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000LL
#define MAXN 10005
#define DIS 1000000

using namespace std;

lld phi(lld n)
{
    lld hi = n;
    lld lo = 1;

    lld limit = sqrt(n);
    ff(i, 2, limit)
    {
        if(n%i == 0)
        {
            hi *= i-1;
            lo *= i;
            while(n%i == 0)
                n/=i;
        }
    }
    if(n > 1)
    {
        hi *= n-1;
        lo *= n;
    }
    return hi/lo;
}

int main()
{
    lld ret = 0;
    ff(i, 2, 1000000)
    {
        if(i % 100000 == 0) cout<<i<<endl;
        ret += phi(i);
    }
    cout<<ret<<endl;
    return 0;
}
