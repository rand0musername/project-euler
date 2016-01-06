// RandomUsername (Nikola Jovanovic)
// Project Euler
// 117

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

int main()
{
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    ff(i, 4, 50)
    {
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3] +DP[i-4];
    }
    cout<<DP[50]<<endl;
    return 0;
}
