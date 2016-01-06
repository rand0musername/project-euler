// RandomUsername (Nikola Jovanovic)
// Project Euler
// 026

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
#define MAXN 3000005

using namespace std;

vector<int> digs;
int p, maxp, dig;

void FillDigs(int b)
{
    int a = 10;
    ff(i, 1, 10000)
    {
        digs.push_back(a / b);
        a -= (a/b) * b;
        a *= 10;
    }
    return;
}

int Period()
{
    ff(T, 1, 1000)
    {
        bool is = true;

        fb(i, 9999, 9999-T+1)
        {
            //starts here
            if(digs[i] != digs[i-T])
                is = false;
        }

        if(is) return T;
    }
    return 0;
}

int main()
{
    ff(d, 2, 999)
    {
        digs.clear();
        FillDigs(d);
        p = Period();
        if(p > maxp)
        {
            maxp = p;
            dig = d;
        }
    }
    printf("%d\n", dig);
    return 0;
}
