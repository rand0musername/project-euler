// RandomUsername (Nikola Jovanovic)
// Project Euler
// 034

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

int f[15];
lld sum;

int F(int i)
{
    int ret = 0;
    while(i > 0)
    {
        int curr = i % 10;
        i /= 10;
        ret += f[curr];
    }
    return ret;
}

int main()
{
    f[0] = 1;
    f[1] = 1;
    ff(i, 2, 10)
        f[i] = f[i-1] * i;
    ff(i, 3, 10000000)
    {
        if(i == F(i))
            sum += i;
    }
    cout<<sum<<endl;
    return 0;
}
