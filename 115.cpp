// RandomUsername (Nikola Jovanovic)
// Project Euler
// 115

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
#define MAXN 1000005

using namespace std;

lld DP[MAXN];

lld F(lld m, lld n)
{
    DP[0] = 1;
    ff(i, 1, n)
    {
        DP[i] = DP[i-1]; //black at the end
        if(i >= m) DP[i]++;
        ff(len, m, i - 1)
        {
            if(i - len - 1 < 0) break;
            DP[i] += DP[i - len - 1];
        }
    }
    return DP[n];
}

int main()
{
    lld n = 1;
    while(1)
    {
        if(F(50, n) > 1000000)
        {
            cout<<n<<endl;
            return 0;
        }
        n++;
    }
    return 0;
}
