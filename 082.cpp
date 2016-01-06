// RandomUsername (Nikola Jovanovic)
// Project Euler
// 082

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
#define INF 1000000000000000000LL
#define MAXN 10005

using namespace std;

int a[MAXN][MAXN];
int DP[MAXN][MAXN];

int main()
{
    freopen("082.in","r",stdin);
    ff(i, 1, 80)
        ff(j, 1, 80)
            scanf("%d", &a[i][j]);

    ff(i, 1, 80)
        DP[i][1] = a[i][1];

    ff(j, 1, 80)
    {
        ff(i, 1, 80)
            DP[i][j+1] = DP[i][j] + a[i][j+1];
        ff(i, 1, 80)
        {
            int curr = DP[i][j];
            ff(k, i+1, 80)
            {
                curr += a[k][j];
                DP[k][j+1] = min(DP[k][j+1], curr + a[k][j+1]);
            }
            curr = DP[i][j];
            fb(k, i-1, 1)
            {
                curr += a[k][j];
                DP[k][j+1] = min(DP[k][j+1], curr + a[k][j+1]);
            }
        }
    }

    int ret = DP[1][80];
    ff(i, 1, 80)
        ret = min(ret, DP[i][80]);
    cout<<ret<<endl;
    return 0;
}
