// RandomUsername (Nikola Jovanovic)
// Project Euler
// 023

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
#define MAXN 29005

using namespace std;

bool abu[MAXN];

int SumDiv(int n)
{
    int ret = 1;

    int limit = sqrt(n);
    ff(i, 2, limit)
    {
        if(n % i == 0)
        {
            ret += i + n/i;
        }
    }
    if(limit * limit == n) ret -= limit;
    return ret;
}

bool CanBe(int n)
{
    ff(i, 1, n/2)
    {
        if(abu[i] && abu[n-i])
        {
            return true;
        }
    }
    return false;
}

int main()
{

    ff(i, 1, MAXN - 5)
    {
        if(SumDiv(i) > i)
            abu[i] = true;
    }

    lld ret = 0;
    ff(i, 1, MAXN - 5)
    {
        if(!CanBe(i))
        {
            ret += i;
        }
    }
    cout<<ret<<endl;
    return 0;
}
