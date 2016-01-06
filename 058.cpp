// RandomUsername (Nikola Jovanovic)
// Project Euler
// 058

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
#define MAXN 1000005

using namespace std;

bool IsPrime(int n)
{
    if(n == 1) return false;

    int limit = sqrt(n);
    ff(i, 2, limit)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    double rat;
    int it = 1;
    int prim = 0;
    int curr = 1;
    int inc = 2;
    while(1)
    {
        ff(i, 1, 4)
        {
            it++;
            if(IsPrime(curr)) prim++;
            rat = 1.0 * prim / it;
            if(inc > 4 && rat < 0.1)
            {cout<<inc+1<<endl; return 0;}
            curr += inc;
        }
        inc += 2;
    }

    return 0;
}
