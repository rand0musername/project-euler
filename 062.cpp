// RandomUsername (Nikola Jovanovic)
// Project Euler
// 062

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

struct dat
{
    lld bas;
    lld val;
    lld digs[25];
    string D;
    lld DP;

    const bool operator<(const dat b)
    const
    {
        if(D == b.D) return val > b.val;
        return D < b.D;
    }
};

void GetDigs(dat& x)
{
    lld n = x.val;
    lld ret = 0;
    while(n > 0)
    {
        ret++;
        x.digs[ret] = n%10;
        n /= 10;
    }

    sort(x.digs+1, x.digs+1+ret);
    x.D = "";
    ff(i, 1, ret)
    {
        x.D += x.digs[i] + '0';
    }
}


dat a[MAXN];
lld minn;

int main()
{
    minn = INF;

    ff(i, 1, 10000)
    {
        a[i].val = i*i*i;
        GetDigs(a[i]);
    }
    sort(a+1, a+10001);
    ff(i, 1, 10000)
    {
        if(a[i].D == a[i-1].D)
            a[i].DP = a[i-1].DP+1;
        else
            a[i].DP = 1;
        if(a[i].DP == 5)
        {
            minn = min(minn, a[i].val);
        }
    }
    cout<<minn<<endl;
    return 0;
}
