// RandomUsername (Nikola Jovanovic)
// Project Euler
// 043

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
#define MAXN 3000005

using namespace std;

lld sum;
lld bae[10] = {0,1,2,3,4,5,6,7,8,9};

lld ToNum()
{
    lld ret = 0;
    ff(i, 0, 9)
    {
        ret *= 10;
        ret += bae[i];
    }
    return ret;
}

lld Num(int a)
{
    return bae[a]*100 + bae[a+1]*10 + bae[a+2];
}

lld primz[8] = {0,2,3,5,7,11,13,17};

bool GoodBae()
{
    ff(i, 1, 7)
    {
        if(Num(i) % primz[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    int cnt = 0;
    do
    {
        if(GoodBae())
        {
            sum += ToNum();
        }
        cnt++;
    }
    while(next_permutation(bae,bae+10));
    cout<<sum<<endl;
    return 0;
}
