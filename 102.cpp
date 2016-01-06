// RandomUsername (Nikola Jovanovic)
// Project Euler
// 102

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
#define MAXN 2000005

using namespace std;

struct trian
{
    par a, b, c;
};

trian t[1005];
par infi, orig;
int ret;

int AreaD(par a, par b, par c)
{
    int ret = (a.fi+b.fi)*(a.se-b.se) + (b.fi+c.fi)*(b.se-c.se) + (c.fi+a.fi)*(c.se-a.se);
    return (int)(abs(ret));
}

int main()
{
    infi.fi = infi.se = 1000000;
    orig.fi = orig.se = 0;

    // formatted the input file for easier input
    freopen("102.in", "r", stdin);
    ff(i, 1, 1000)
    {
        scanf("%d %d %d %d %d %d", &t[i].a.fi, &t[i].a.se, &t[i].b.fi, &t[i].b.se, &t[i].c.fi, &t[i].c.se);
        if(AreaD(t[i].a, t[i].b, t[i].c) == AreaD(t[i].a, t[i].b, orig) + AreaD(t[i].b, t[i].c, orig) + AreaD(t[i].c, t[i].a, orig))
            ret++;
    }
    cout << ret << endl;
    return 0;
}
