// RandomUsername (Nikola Jovanovic)
// Project Euler
// 067

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
#define MAXN 105

using namespace std;

int a[MAXN][MAXN];
int DP[MAXN][MAXN];

int main()
{
    freopen("067.in", "r", stdin);
    int ret = 0;

    int n = 100;
    ff(i, 1, n)
    {
        ff(j, 1, i)
        {
            scanf("%d", &a[i][j]);
            DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + a[i][j];
            if(i == n) ret = max(ret, DP[i][j]);
        }
    }

    cout<<ret<<endl;
    return 0;
}
