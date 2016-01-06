// RandomUsername (Nikola Jovanovic)
// Project Euler
// 003

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(int i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 105

using namespace std;

lld n = 600851475143;

lld laFa(lld n)
{
    lld best;
    lld limit = sqrt(n);
    ff(i, 2, limit)
    {
        while(n%i == 0)
        {
            n /= i;
            best = i;
        }
    }
    if(n > 1) best = n;
    return best;
}

int main()
{
    printf("%lld\n", laFa(n));
    return 0;
}
