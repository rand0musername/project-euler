// RandomUsername (Nikola Jovanovic)
// Project Euler
// 205

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
#define MAXN 2000005

using namespace std;

int F() {return rand()%4 + 1;} //9
int S() {return rand()%6 + 1;} //6

int freqF[50];
int freqS[50];

void genF(int lvl, int sum)
{
    if(lvl == 10)
    {
        freqF[sum]++;
        return;
    }
    ff(i, 1, 4)
        genF(lvl+1, sum+i);
}
void genS(int lvl, int sum)
{
    if(lvl == 7)
    {
        freqS[sum]++;
        return;
    }
    ff(i, 1, 6)
        genS(lvl+1, sum+i);
}

lld all, fwin;
double rat;

int main()
{
    genF(1, 0);
    genS(1, 0);

    ff(i, 1, 36)
        ff(j, 1, 36)
        {

            all += freqF[i] * freqS[j];
            if(i > j)
                fwin += freqF[i] * freqS[j];
        }
    rat = 1.0 * fwin / all;
    printf("%0.7f\n", rat);
    return 0;
}
