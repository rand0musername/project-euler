// RandomUsername (Nikola Jovanovic)
// Project Euler
// 051

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
#define MAXN 1000005

using namespace std;

int digs[10];
inline int Digits(int n)
{
    int ret = 0;
    while(n > 0)
    {
        ret++;
        digs[ret] = n%10;
        n /= 10;
    }
    return ret;
}

int digz;

inline int GetNum()
{
    int ret = 0;
    fb(i, digz, 1)
    {
        ret *= 10;
        ret += digs[i];
    }
    return ret;
}

int comp[MAXN];
int main()
{
    ff(i, 2, MAXN-5)
    {
      if(!comp[i])
      {
          for(lld j=i*i; j<=MAXN-5; j += i)
          {
              comp[j] = true;
          }
      }
    }


    for(int n=1; n<=1000000; n+=2)
    {
        if(comp[n]) continue;
        digz = Digits(n);
        int MASKS = (1<<digz);
        ff(MASK, 0, MASKS-1)
        {
            int cif = -1;
            bool ok = true;

            ff(bit, 0, digz-1)
                if( (MASK & (1 << bit)) != 0 )
                {
                    if(cif == -1)
                        cif = digs[bit+1];
                    else if(cif != digs[bit+1])
                    {ok = false; break;}
                }
            if(!ok) continue;
            int primz = 0;
            ff(i, 0, 9)
            {
                if(i == 0 && (MASK & (1 << digz-1)) != 0)
                    continue;
                ff(bit, 0, digz-1)
                    if( (MASK & (1 << bit)) != 0 )
                    {
                       digs[bit+1] = i;
                    }
                if(!comp[GetNum()]) primz++;
            }
            if(primz == 8) {cout<<n<<endl; return 0;}
             ff(bit, 0, digz-1)
                    if( (MASK & (1 << bit)) != 0 )
                    {
                       digs[bit+1] = cif;
                    }
        }
    }
    return 0;
}

