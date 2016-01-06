// RandomUsername (Nikola Jovanovic)
// Project Euler
// 085

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
#define INF 1000000000LL
#define MAXN 10005
#define DIS 1000000

using namespace std;

const lld mak = 8000000LL;

lld mindif = mak;
lld P;

void Update(lld a, lld b)
{
    lld S = a * (a+1) * b * (b+1);
    if(abs(S - mak) < mindif)
    {
        mindif = abs(S - mak);
        P = a*b;
    }
}

int main()
{
    lld limit = (lld)(sqrt(mak));
    ff(a, 1, limit)
    {
        lld C = mak / (a*a + a);
        double D = sqrt(4.0*C+1.0);
        double S1 = (-1.0 + D) / 2.0;
        double S2 = (-1.0 - D) / 2.0;
        Update(a, floor(S1));
        Update(a, floor(S2));
        Update(a, ceil(S1));
        Update(a, ceil(S2));
    }
    cout<<P<<endl;
    return 0;
}
