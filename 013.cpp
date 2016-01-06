// RandomUsername (Nikola Jovanovic)
// Project Euler
// 013

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

string s[105];
stack<int> ret;

int main()
{
    freopen("013.in", "r", stdin);
    ff(i, 1, 100)
    {
        cin >> s[i];
    }

    int carry = 0;
    fb(it, 49, 0)
    {
        ff(i, 1, 100)
            carry += s[i][it] - '0';
        ret.push(carry % 10);
        carry /= 10;
    }
    while(carry > 0)
    {
        ret.push(carry % 10);
        carry /= 10;
    }
    ff(i, 1, 10)
    {
        cout<<ret.top();
        ret.pop();
    }
    return 0;
}
