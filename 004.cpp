// RandomUsername (Nikola Jovanovic)
// Project Euler
// 004

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

bool IsPalin(lld n)
{
    vector<int> dig;
    while(n > 0)
    {
        dig.push_back(n % 10);
        n /= 10;
    }
    int sz = dig.size();
    ff(i, 0, sz-1)
    {
        if(dig[i] != dig[sz-i-1])
            return false;
    }
    return true;
}

int main()
{
    int best = 0;

    ff(i, 100, 999)
    {
        ff(j, i, 999)
        {
            if(IsPalin(i * j) && i*j > best)
                best = i*j;
        }
    }
    printf("%d\n", best);
    return 0;
}
