// RandomUsername (Nikola Jovanovic)
// Project Euler
// 033

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

bool Ok(int a, int b)
{
    if((b%10) == (a%10) && a * (b/10) == b * (a/10)) return true;
    if((b/10) == (a%10) && a * (b%10) == b * (a/10)) return true;
    if((b%10) == (a/10) && a * (b/10) == b * (a%10)) return true;
    if((b/10) == (a/10) && a * (b%10) == b * (a%10)) return true;
    return false;
}

int main()
{
    int A = 1;
    int B = 1;

    ff(a, 10, 99)
    {
        ff(b, a+1, 99)
        {
            if(a%10 == 0 && b%10 == 0) continue;
            if(Ok(a, b))
            {
                A *= a;
                B *= b;
            }
        }
    }
    printf("%d\n", B / __gcd(A, B));
    return 0;
}
