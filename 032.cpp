// RandomUsername (Nikola Jovanovic)
// Project Euler
// 032

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

int bae[9] = {1,2,3,4,5,6,7,8,9};

set<int> don;
int cnt;

int Good(int i, int j)
{
    int a, b, c;
    a = b = c = 0;

    ff(idx, 0, i)
    {
        a *= 10;
        a += bae[idx];
    }
    ff(idx, i+1, j-1)
    {
        b *= 10;
        b += bae[idx];
    }
    ff(idx, j, 8)
    {
        c *= 10;
        c += bae[idx];
    }

    if(a*b == c) return c;
    return -1;
}

int main()
{
    do
    {
        ff(i, 0, 6)
            ff(j, i+2, 8)
            {
                int num = Good(i, j);
                if(num == -1) continue;
                if(don.find(num) == don.end())
                {
                    cnt+=num;
                    don.insert(num);
                }
            }
    }
    while(next_permutation(bae,bae+9));
    cout<<cnt<<endl;
    return 0;
}
