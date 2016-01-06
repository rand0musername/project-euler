// RandomUsername (Nikola Jovanovic)
// Project Euler
// 010

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(int i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 2000005

using namespace std;

bool comp[MAXN];

int main()
{
    ff(i, 2, 2000)
    {
        if(!comp[i])
        {
            for(int j = i*i; j <= 2000000; j += i)
                comp[j] = true;
        }
    }

    lld ret = 0;
    ff(i, 2, 2000000)
        ret += (!comp[i]) * i;
    cout<<ret<<endl;

}
