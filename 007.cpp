// RandomUsername (Nikola Jovanovic)
// Project Euler
// 007

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

bool IsPrime(lld n)
{
    lld best;
    lld limit = sqrt(n);
    ff(i, 2, limit)
    {
        if(n%i == 0)
        {
           return false;
        }
    }
    return true;
}

int main()
{
    int cnt = 0;
    int curr = 1;
    while(cnt < 10001)
    {
        curr++;
        if(IsPrime(curr))
            cnt++;
    }
    cout<<curr<<endl;
}
