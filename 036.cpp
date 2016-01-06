// RandomUsername (Nikola Jovanovic)
// Project Euler
// 036

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

using namespace std;

string Strinag(int n)
{
    string s = "";
    while(n > 0)
    {
        s += (n%10) + '0';
        n /= 10;
    }
    return s;
}

string Binary(int n)
{
    string s = "";
    while(n > 0)
    {
        s += (n%2) + '0';
        n /= 2;
    }
    return s;
}

bool Palin(string s)
{
    int sz = s.size();
    ff(i, 0, sz-1)
    {
        if(s[i] != s[sz - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    lld sum = 0;
    ff(i, 1, 1000000)
    {
        if(Palin(Strinag(i)) && Palin(Binary(i)))
            sum += i;
    }
    cout<<sum;
    return 0;
}
