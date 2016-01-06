// RandomUsername (Nikola Jovanovic)
// Project Euler
// 035

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
#define MAXN 1000005

using namespace std;

bool comp[MAXN];

bool Ok(int n)
{
    int curr;

    while(n > 0)
    {
        curr = n%10;
        if( curr != 1 && curr != 3 && curr != 5 && curr != 7 && curr != 9)
            return false;
        n /= 10;
    }
    return true;
}

int Rot(int n)
{
    int n1 = n;

    int cif;
    int deg10 = 1;
    while(n > 0)
    {
        deg10 *= 10;
        cif = n%10;
        n /= 10;
    }
    deg10 /= 10;
    n = (n1 % deg10) * 10 + cif;
    return n;
}

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

    int cnt = 0;

    ff(i, 1, MAXN-5)
    {
        int n = i;
        if(!Ok(n)) continue;

        bool is = true;
        ff(j, 1, 6)
        {
            if(comp[n])
                is = false;
            n = Rot(n);
        }
        if(is) {cnt++;}
    }
    cout<<cnt<<endl;
    return 0;
}
