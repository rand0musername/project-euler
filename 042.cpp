// RandomUsername (Nikola Jovanovic)
// Project Euler
// 042

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

int Score(string s)
{
    int ret = 0;

    int sz = s.size();
    ff(i, 0, sz - 1)
    {
        ret += s[i] - 'A' + 1;
    }
    return ret;
}

bool Trian(int m)
{
    m *= 2;
    int s = sqrt(m);
    if(s * (s+1) == m)
        return true;
    return false;
}

char pom[100];

int main()
{
    freopen("042.in", "r", stdin);

    int ret = 0;
    string s;
    while(scanf("%s", pom) == 1)
    {
        s = pom;

        if(Trian(Score(s)))
        {
            ret++;
        }
    }
    cout<<ret<<endl;
    return 0;
}
