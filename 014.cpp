// RandomUsername (Nikola Jovanovic)
// Project Euler
// 014

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
#define MAXN 2000005

using namespace std;

lld ChainLen(lld n)
{
    if(n == 1) return 1;
    if(n % 2 == 0) return 1 + ChainLen(n / 2);
    else return 1 + ChainLen (3*n + 1);
}

int main()
{
    lld best = 1;
    lld maks = 1;
    ff(i, 1, 1000000)
    {
        lld curr = ChainLen(i);
        if(curr > maks)
        {
            maks = curr;
            best = i;
        }
    }
    cout<<best<<endl;
    return 0;
}
