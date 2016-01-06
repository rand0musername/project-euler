// RandomUsername (Nikola Jovanovic)
// Project Euler
// 041

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
#define MAXN 10000005

using namespace std;

bool comp[MAXN];
lld bae[7] = {1,2,3,4,5,6,7}; //3 | 8 and 9

lld ToNum()
{
    lld ret = 0;
    ff(i, 0, 6)
    {
        ret *= 10;
        ret += bae[i];
    }
    return ret;
}

int ret;

int main()
{
    for(lld i=2; i<=MAXN-5; i++)
    {
      if(!comp[i])
      {
          for(lld j=i*i; j<=MAXN-5; j += i)
          {
              comp[j] = true;
          }
      }
    }

    int i = 0;
    //try 7?
    do
    {
        if(!comp[ToNum()])
            ret = ToNum();
    }
    while(next_permutation(bae,bae+7));

    printf("%d\n", ret);

    return 0;
}
