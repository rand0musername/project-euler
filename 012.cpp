// RandomUsername (Nikola Jovanovic)
// Project Euler
// 012

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(lld i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 2000005

using namespace std;

bool comp[MAXN];

int main()
{
    ff(i, 1, 100000)
    {
        lld t = i * (i+1) / 2;
        lld lim = sqrt(t);
        lld dv = 0;
        ff(j, 2, lim)
        {
            if(t % j == 0)
                dv += 2;
        }
        if(lim * lim == t) dv--;
        if(dv >= 501)
            {cout<<t<<endl; return 0;}
    }
    return 0;
}
