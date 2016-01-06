// RandomUsername (Nikola Jovanovic)
// Project Euler
// 053

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
#define MAXN 29005

using namespace std;

int C[150][150];
int ret;

int main()
{
    ff(n, 1, 100)
    {
        ff(k, 0, n)
        {
            if(k == 0) C[n][k] = 1;
            else if(k == 1) C[n][k] = n;
            else C[n][k] = C[n-1][k] + C[n-1][k-1];

            if(C[n][k] > 1000000)
            {
                C[n][k] = 1000001;
                ret++;
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}

