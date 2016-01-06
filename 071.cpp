// RandomUsername (Nikola Jovanovic)
// Project Euler
// 071

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
#define MAXN 10005

using namespace std;

struct raz
{
    int n;
    int d;
    const bool operator>(const raz b)
    {
        return 1.0 * n / d >  1.0 * b.n / b.d;
    }
};

int main()
{
    raz best({1, 3});
    ff(i, 4, 1000000)
    {
        if(i % 7 == 0) continue;
       raz curr({3*i/7, i});
       if(curr > best)
        best = curr;
    }
    cout<<best.n/__gcd(best.n, best.d)<<endl;
    return 0;
}
