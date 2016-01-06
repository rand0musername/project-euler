// RandomUsername (Nikola Jovanovic)
// Project Euler
// 114

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

lld DP[MAXN];

int n = 50;
int m = 3;

int main()
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
    cout<<DP[n]<<endl;
    return 0;
}
