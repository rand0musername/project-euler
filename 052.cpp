// RandomUsername (Nikola Jovanovic)
// Project Euler
// 052

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

int d[30][10];
bool moze;

int main()
{
    int P = 6;

    ff(i, 1, 10000000)
    {
        ff(p, 1, P)
        {
            int n = i*p;
            while(n > 0)
            {
                d[n%10][p]++;
                n /= 10;
            }
        }

        moze = true;
        ff(k, 0, 9)
        {
            int cur = d[k][1];
            ff(j, 1, P)
            {
                if(cur != d[k][j])
                    moze = false;
                d[k][j] = 0;
            }

        }
        if(moze)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
