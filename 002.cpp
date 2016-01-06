// RandomUsername (Nikola Jovanovic)
// Project Euler
// 002

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

lld sum;
lld last, curr;

int main()
{
    last = 1;
    curr = 2;

    sum = 2;

    while(curr <= 4000000)
    {
        curr = last + curr;
        last = curr - last;

        sum += curr * (!(curr & 1));
    }
    printf("%lld\n", sum);
    return 0;
}
