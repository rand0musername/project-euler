// RandomUsername (Nikola Jovanovic)
// Project Euler
// 030

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

int SumPow(int n)
{
    int ret = 0;
    while(n > 0)
    {
        ret += (int)pow(n%10, 5);
        n /= 10;
    }
    return ret;
}

int main()
{
    int ret = 0;

    ff(i, 10, 1000000)
    {
        if(SumPow(i) == i)
            ret += i;
    }

    cout<<ret<<endl;
}
