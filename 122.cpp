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
#define MAXN 1000005

using namespace std;

int DP[205];
int ret;

int main()
{
    DP[1] = 0;
    ff(i, 2, 200)
    {
        if(i % 2 == 1)
            DP[i] = 1 + DP[i-1];
        else
            DP[i] = 1 + min(DP[i-1], DP[i/2]);
        ret += DP[i];
        cout<<i<<" "<<DP[i]<<endl;
    }
    cout<<ret<<endl;
    return 0;
}
