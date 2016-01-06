// RandomUsername (Nikola Jovanovic)
// Project Euler
// 047

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
#define EPS

using namespace std;

int Dists(int n)
{
    int limit = sqrt(n);
    int cnt = 0;
    ff(i, 2, limit)
    {
        if(n%i == 0)
            cnt++;
        while(n%i == 0)
        {
            n /= i;
        }
    }
    if(n > 1) cnt++;
    return cnt;
}

int main()
{
    ff(i, 1, 1000000)
    {
        if(Dists(i) == 4 && Dists(i+1) == 4 && Dists(i+2) == 4 && Dists(i+3) == 4)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
