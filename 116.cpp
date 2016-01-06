// RandomUsername (Nikola Jovanovic)
// Project Euler
// 116

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

lld DP[MAXN][5];

int main()
{
    DP[1][2] = DP[1][3] = DP[1][4] = 0;
    DP[2][2] = 1; DP[2][3] = 0; DP[2][4] = 0;
    DP[3][2] = 2; DP[3][3] = 1; DP[3][4] = 0;
    ff(i, 4, 50)
    {
        ff(j, 2, 4)
            DP[i][j] = 1 + DP[i-1][j] + DP[i-j][j];
    }
    cout<<DP[50][2] + DP[50][3] + DP[50][4];
    return 0;
}
