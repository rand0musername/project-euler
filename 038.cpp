// RandomUsername (Nikola Jovanovic)
// Project Euler
// 038

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

string itos(int n)
{
    string s = "";
    while(n > 0)
    {
        s += '0' + n%10;
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool Pandigital(string s)
{
    sort(s.begin(), s.end());
    ff(i, 0, 8)
    {
        if(s[i] != i+1+'0')
            return false;
    }
    return true;
}

vector<string> v;

int main()
{
    string s;

    ff(a, 1, 9999)
    {
        s = "";
        ff(i, 1, 10)
        {
            s += itos(a*i);
            if(s.size() >= 9)
                break;
        }
        if(s.size() > 9) continue;
        if(Pandigital(s)) v.push_back(s);
    }

    sort(v.begin(), v.end());
    int sz = v.size();
    cout<<v[sz-1]<<endl;
    return 0;
}
