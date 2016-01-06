// RandomUsername (Nikola Jovanovic)
// Project Euler
// 206

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

inline bool OK(lld n)
{
    n /= 10000;
    int iter = 8;
    while(n > 0)
    {
        if(n%10 != iter)
            return false;
        n /= 100;
        iter--;
    }
    return true;
}

int main()
{
    for(lld n = 1000000030LL; n <= 1420000000LL; n += 100)
    {
        if(OK(n*n)) {cout<<n<<endl; return 0;}
        lld m = n + 40;
        if(OK(m*m)) {cout<<m<<endl; return 0;}
    }
    return 0;
}
