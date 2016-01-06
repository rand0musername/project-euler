// RandomUsername (Nikola Jovanovic)
// Project Euler
// 006

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
#define MAXN 105

using namespace std;

int main()
{
    int diff = 100*101/2;
    diff *= diff;
    ff(i, 1, 100)
    {
        diff -= i*i;
    }
    if(diff<0) diff*=-1;
    cout<<diff<<endl;
    return 0;
}
