// RandomUsername (Nikola Jovanovic)
// Project Euler
// 092

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(lld i=a; i<=b; i++)
#define fb(i,a,b) for(lld i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 105

using namespace std;

int Trans(int n)
{
    int ret = 0;
    while(n > 0)
    {
        ret += (n%10) * (n%10);
        n /= 10;
    }
    return ret;
}

int main()
{
    int cnt = 0;

    ff(i, 1, 10000000)
    {
        int curr = i;
        while(1)
        {
            if(curr == 1) break;
            if(curr == 89) {cnt++; break;}
            curr = Trans(curr);
        }
    }
    cout << cnt << endl;
    return 0;
}
