// RandomUsername (Nikola Jovanovic)
// Project Euler
// 046

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
#define MAXN 10005

using namespace std;

bool comp[MAXN];

int main()
{
    comp[1] = true;
    ff(i, 2, MAXN-5)
    {
        if(comp[i]) continue;
        for(int j=i*i; j<=MAXN-5; j += i)
            comp[j] = true;
    }


    for(int i=3; i<=MAXN-5; i += 2)
    {
        if(!comp[i]) continue;

        bool can = false;

        ff(sq, 1, i/2)
        {
            if(i - 2 * sq * sq < 2) break;

            if(!comp[i - 2 * sq * sq])
            {
                can = true;
            }
        }

        if(!can)
        {
            cout<<i<<endl;
            break;
        }
    }
}
