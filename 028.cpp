// RandomUsername (Nikola Jovanovic)
// Project Euler
// 028

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

int main()
{
    lld sum = 1;
    lld curr = 1;
    ff(i, 2, 1000)
    {
        if(i%2 == 1) continue;

        ff(j, 1, 4)
        {
            curr += i;
            sum += curr;
        }
    }
    cout<<sum<<endl;
    return 0;
}
