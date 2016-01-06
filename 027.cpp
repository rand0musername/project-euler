// RandomUsername (Nikola Jovanovic)
// Project Euler
// 027

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

int comp[MAXN];

int Score(int a, int b)
{
    ff(i, 0, 1000)
    {
        if(comp[i*i + i*a + b])
            return i;
    }
    return 1001;
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

    int best = 0;
    int curr;
    int bestMul = 0;

    ff(a, -999, 999)
        ff(b, -999, 999)
        {
            curr = Score(a, b);
            if(curr > best)
            {
                best = Score(a, b);
                bestMul = a*b;
            }
        }
    cout<<bestMul<<endl;
    return 0;
}
