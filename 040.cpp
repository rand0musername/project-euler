// RandomUsername (Nikola Jovanovic)
// Project Euler
// 040

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
#define MAXN 10005

using namespace std;

vector<int> d;

void Add(int n)
{
    stack<int> s;

    while(n > 0)
    {
        s.push(n%10);
        n/=10;
    }

    while(!s.empty())
    {
        d.push_back(s.top());
        s.pop();
    }

}

int main()
{
    d.push_back(0);

    ff(i, 1, 1000000)
    {
        Add(i);
    }
    cout<<d[1]*d[10]*d[100]*d[1000]*d[10000]*d[100000]*d[1000000]<<endl;
}
