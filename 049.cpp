// RandomUsername (Nikola Jovanovic)
// Project Euler
// 049

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

int comp[MAXN];
int digs[3][10];

bool AllPerm(int a, int b, int c)
{
    int a1 = a;
    while(a > 0){  digs[0][a%10]++; a/=10;  }
    while(b > 0){  digs[1][b%10]++; b/=10;  }
    while(c > 0){  digs[2][c%10]++; c/=10;  }

    bool is = true;

    ff(i, 0, 9)
    {

        if(digs[0][i] != digs[1][i] || digs[1][i] != digs[2][i])
        {
            is = false;
        }
        digs[0][i] = digs[1][i] = digs[2][i] = 0;
    }
    return is;
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

    ff(a, 1000, 9999)
    {
        if(comp[a]) continue;
        ff(i, 1, 9999)
        {
            if(i%2 == 1) continue;
            int b = a + i;
            int c = a + i*2;
            if(b<=9999 && c<=9999 && !comp[a] && !comp[b] && !comp[c] && AllPerm(a,b,c))
                cout<<a<<b<<c<<endl;
        }
    }

    return 0;
}
