// RandomUsername (Nikola Jovanovic)
// Project Euler
// 044

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

set<int> pen;

int main()
{
    int D = INF;

    ff(n, 1, 10000)
    {
        int p = n * (3*n-1) / 2;
        pen.insert(p);
    }
    ff(a, 1, 10000)
    {
        int pa = a * (3*a-1) / 2;
        ff(b, a+1, 10000)
        {
            int pb = b * (3*b-1) / 2;
            if(pen.find(pa+pb) != pen.end() && pen.find(pb-pa) != pen.end())
                D = min(D, pb - pa);
        }
    }
    cout<<D<<endl;
    return 0;
}
