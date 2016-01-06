// RandomUsername (Nikola Jovanovic)
// Project Euler
// 191

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

int B[40];
int S[40];

int main()
{
    B[1] = 2; B[2] = 4; B[3] = 7; B[4] = 13;
    S[1] = 1; S[2] = 4; S[3] = 12; S[4] = 30;
    ff(i, 5, 30)
    {
        B[i] = 2*B[i-2]+2*B[i-3]+B[i-4];
        S[i] = 2*S[i-2]+3*B[i-2]+2*S[i-3]+3*B[i-3]+2*B[i-4]+S[i-4];
    }
    cout<<B[30] + S[30]<<endl;
    return 0;
}
