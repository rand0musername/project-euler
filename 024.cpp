// RandomUsername (Nikola Jovanovic)
// Project Euler
// 024

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

int x[10] = {0,1,2,3,4,5,6,7,8,9};

int main()
{
    ff(i, 1, 999999)
    {
        next_permutation(x, x+10);
    }
    ff(i, 0, 9)
        cout<<x[i];
    return 0;
}
