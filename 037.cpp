// RandomUsername (Nikola Jovanovic)
// Project Euler
// 037

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
int L[MAXN];
int R[MAXN];
int cnt;
int sum;

int RemoveFirstDigit(int i)
{
    int n = i;
    int dig = 1;
    while(i > 0)
    {
        dig *= 10;
        i /= 10;
    }
    dig /= 10;
    return n % dig;
}

int main()
{
    ff(i, 2, MAXN-5)
    {
      if(!comp[i])
      {
          if(i <= 9)
          {
              L[i] = true;
              R[i] = true;
          }
          else
          {
              L[i] = L[i / 10];
              R[i] = R[RemoveFirstDigit(i)];
              if(L[i] && R[i])
              {
                  cnt++;
                  sum += i;
              }
          }
          //it is a prime
          for(lld j=i*i; j<=MAXN-5; j += i)
          {
              comp[j] = true;
          }
      }
    }
    cout<<sum<<endl;
    return 0;
}
