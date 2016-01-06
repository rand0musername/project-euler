// RandomUsername (Nikola Jovanovic)
// Project Euler
// 055

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(lld i=a; i<=b; i++)
#define fb(i,a,b) for(lld i=a; i>=b; i--)
#define par pair<lld, lld>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 29005

using namespace std;

lld Reverse(lld n)
{
    stack<lld> s;
    while(n > 0)
    {
        s.push(n % 10);
        n /= 10;
    }

    stack<lld> t;
    while(!s.empty())
    {
        t.push(s.top());
        s.pop();
    }

    lld m = 0;
    while(!t.empty())
    {
        m *= 10;
        m += t.top();
        t.pop();
    }
    return m;
}

lld Warp(lld n)
{
    return n + Reverse(n);
}

bool IsPalin(lld n)
{
    if(n == Reverse(n))
        return true;
    return false;
}

int main()
{
    lld cnt = 0;
    ff(n, 1, 10000)
    {
        lld curr = n;
        cnt++;

        ff(k, 1, 50)
        {
            curr = Warp(curr);
            if(IsPalin(curr))
            {
                cnt--;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

