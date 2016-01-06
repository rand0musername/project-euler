// RandomUsername (Nikola Jovanovic)
// Project Euler
// 073

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
#define DIS 1000000

using namespace std;

int ret;

unordered_set<lld> s;

int main()
{
    ff(d, 1, 12000)
    {
        ff(n, 1, d)
        {
            lld gcd = __gcd(n, d);
            if(d > 2 * n && d < 3 * n && s.find(n/gcd * DIS + d/gcd) == s.end() )
            {
                    s.insert(n/gcd * DIS + d/gcd);
                    ret++;
            }
        }
    }
    cout<<ret;
    return 0;
}
