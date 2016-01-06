// RandomUsername (Nikola Jovanovic)
// Project Euler
// 097

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
#define INF 1000000000
#define MAXN 29005
#define EPS

using namespace std;

lld MOD = 10000000000LL;

int main()
{
    lld curr = 1;
    ff(i, 1, 7830457)
    {
        curr *= 2;
        curr %= MOD;
    }
    curr *= 28433;
    curr += 1;
    curr %= MOD;
    cout << curr << endl;
    return 0;
}
