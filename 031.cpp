// RandomUsername (Nikola Jovanovic)
// Project Euler
// 031

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
#define MAXN 10000005

using namespace std;

int vals[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
int DP[10][205];
int main()
{
    ff(j, 0, 200)
        DP[1][j] = 1;
    ff(i, 2, 8)
    {
        DP[i][0] = 1;
        ff(j, 1, 200)
        {
            ff(k, 0, 200)
            {
                if(j - k*vals[i] < 0) break;
                DP[i][j] += DP[i-1][j - k*vals[i]];
            }
        }
    }
    cout<<DP[8][200]<<endl;
}
