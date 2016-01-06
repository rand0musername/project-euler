// RandomUsername (Nikola Jovanovic)
// Project Euler
// 099

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
#define MAXN 1005

using namespace std;

struct num
{
    int bas;
    int exp;
    int idx;
    double val;
    const bool operator<(const num b)
    const
    {
        return val < b.val;
    }
};

num a[MAXN];

int main()
{
    freopen("099.in", "r", stdin);
    ff(i, 1, 1000)
    {
        scanf("%d,%d", &a[i].bas, &a[i].exp);
        a[i].idx = i;
        a[i].val = 1.0 * a[i].exp * log(a[i].bas);
    }
    sort(a+1, a+1001);
    printf("%d", a[1000].idx);
    return 0;
}

