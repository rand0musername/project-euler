// RandomUsername (Nikola Jovanovic)
// Project Euler
// 173

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

using namespace std;

lld n = 1000000;

int main()
{
    lld ret = 0, curr;
    //even
    for(lld b=1; 8*b+4<=n; b++)
    {
        lld t = 4 * (b*b + 2*b + 1) - n;

        if(t < 0)
            curr = b;
        else
            curr = min(b, b - (lld)ceil(sqrt(1.0*t/4.0)) + 1);
        ret += curr;
    }
    //odd
    for(lld b=0; 8*b+8<=n; b++)
    {
        lld t = 4 * (b*b + 3*b + 2) + 1 - n;
        if(t < 0)
            curr = b + 1;
        else
            curr = b - (lld)ceil((sqrt(1.0*t) - 1.0) / 2.0) + 1;
        ret += curr;
    }
    cout<<ret<<endl;
    return 0;
}
