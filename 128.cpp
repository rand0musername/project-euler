// RandomUsername (Nikola Jovanovic)
// Project Euler
// 128

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

lld cnt;

bool isprime(lld x)
{
    if(x == 1) return false;

    lld limit = (lld)sqrt(x);
    ff(i, 2, limit)
        if(x % i == 0)
            return false;
    return true;
}

int main()
{
    lld cnt = 2;
    for(lld k=2;;k++)
    {
        if(isprime(6*k-1) && isprime(6*k+1) && isprime(12*k+5))
        {
            cnt++;
            if(cnt == 2000)
            {
                cout<<3*k*k-3*k+2<<endl;
                return 0;
            }
        }
        if(isprime(6*k-1) && isprime(6*k+5) && isprime(12*k-7))
        {
            cnt++;
            if(cnt == 2000)
            {
                cout<<3*k*k+3*k+1<<endl;
                return 0;
            }
        }
    }
    return 0;
}
