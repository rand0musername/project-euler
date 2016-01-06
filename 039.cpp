// RandomUsername (Nikola Jovanovic)
// Project Euler
// 039

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

int curr, best, bestval;

int Calc(int p)
{
    int ret = 0;

    ff(c, 1, p)
    {
        ff(b, 1, c-1)
        {
            int a = p - b - c;
            if(a <= b && a > 0 && a*a + b*b == c*c)
                ret++;
        }
    }

    return ret;
}

int main()
{
    ff(i, 1, 1000)
    {
        curr = Calc(i);
        if(curr > bestval)
        {
            bestval = curr;
            best = i;
        }
    }
    cout<<best<<endl;
    return 0;
}
