// RandomUsername (Nikola Jovanovic)
// Project Euler
// 164

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

lld DP[30][15][15];

lld dp(lld idx, lld l1, lld l2)
{
    if(idx == 0) return 1;

    if(!DP[idx][l1][l2])
    {
        lld ret = 0;
        ff(i, 0, 9)
        {
            if(idx == 1 && i == 0) continue;
            if(i+l1+l2 <= 9)
                ret += dp(idx-1, i, l1);
        }
        DP[idx][l1][l2] = ret;
    }
    return DP[idx][l1][l2];
}

int main()
{
    cout<<dp(20, 0, 0)<<endl;
    return 0;
}
