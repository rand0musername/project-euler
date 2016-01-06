// RandomUsername (Nikola Jovanovic)
// Project Euler
// 022

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
#define MAXN 6005

using namespace std;

string dict[MAXN];
char pom[100];

int Score(string x)
{
    int len = x.size();

    int ret = 0;

    ff(i, 0, len - 1)
    {
        ret += x[i] - 'A' + 1;
    }

    return ret;
}

int main()
{
    // I formatted the file for easier input
    freopen("022.in", "r", stdin);
    int it = 1;

    while( scanf("%s", pom) > 0 ) {dict[it++] = pom;}

    sort(dict+1, dict+it);

    int sum = 0;

    ff(i, 1, it-1)
    {
        sum += Score(dict[i]) * i;
    }

    cout<<sum<<endl;
    return 0;
}
