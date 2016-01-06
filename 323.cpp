// RandomUsername (Nikola Jovanovic)
// Project Euler
// 323

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

const int bits = 32;

inline double C(double i)
{
   return pow((1 - pow(0.5, i)), bits);
}

double ways[100005][50];
double bc[100][100];
double s;

int main()
{
    ff(n, 0, 35)
    {
        ff(k, 0, n)
        {
            if(k == 0) bc[n][k] = 1;
            else if(k == n) bc[n][k] = 1;
            else bc[n][k] = bc[n-1][k] + bc[n-1][k-1];
        }
    }

    ways[0][0] = 1;

    int i = 1;
    int ITERS = 100;
    ff(it, 1, ITERS)
    {
        ff(s1, 0, bits)
        {
            ff(s2, s1, bits)
            {
                ways[i][s2] += ways[i-1][s1] * (1LL<<s1) * bc[bits-s1][s2-s1];
            }
        }
        ff(s2, 0, bits)
        {
            ways[i][s2] /= 1.0*(1LL<<bits);
        }
        s += i * (ways[i][bits] - ways[i-1][bits]);
        i++;
    }
    printf("%0.10f\n", s);
}
