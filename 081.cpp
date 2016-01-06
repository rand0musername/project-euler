// RandomUsername (Nikola Jovanovic)
// Project Euler
// 081

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
#define MAXN 1000005

using namespace std;

int a[100][100];
int DP[100][100];

int main()
{
    freopen("081.in", "r", stdin);
    ff(i, 1, 80)
        ff(j, 1, 80)
            scanf("%d", &a[i][j]);

    ff(i, 0, 81)
        DP[0][i] = DP[i][0] = INF;
    DP[1][1] = a[1][1];

    ff(i, 1, 80)
        ff(j, 1, 80)
            {if(i+j==2) continue; DP[i][j] = a[i][j] + min(DP[i-1][j], DP[i][j-1]);}
    cout<<DP[80][80];
    return 0;
}
