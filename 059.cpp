// RandomUsername (Nikola Jovanovic)
// Project Euler
// 059

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

int pom;
vector<int> numz;
int freq[1000];

int main()
{
    // Tweaked input file for easier input
    freopen("059.in", "r", stdin);
    while(scanf("%d", &pom) == 1)
    {
        numz.push_back(pom);
    }
    int sz = numz.size();

    ff(i, 'a', 'z')
        ff(j, 'a', 'z')
            ff(k, 'a', 'z')
            {
                ff(it, 'a', 'z'+1)
                    freq[it] = 0;
                int ch;
                vector<int> nwz;

                ff(it, 0, sz-1)
                {
                    if(it%3 == 0) ch = i;
                    else if(it%3 == 1) ch = j;
                    else ch = k;

                    int kur =  numz[it] ^ ch;
                    if(kur >= 'A' && kur <= 'Z')
                        kur = kur - 'A' + 'a';
                    if(kur == ' ')
                        freq['a' - 1]++;
                    else if(kur < 'a' || kur > 'z')
                        freq['z'+1]++;
                    else
                        freq[kur]++;

                    nwz.push_back(numz[it] ^ ch);
                }

                int maks = 0;
                int mch = 0;
                ff(it, 'a', 'z'+1)
                {
                    if(freq[it] > maks)
                    {
                        maks = freq[it];
                        mch = it;
                    }
                }

                if(mch != 'z'+1)
                {
                        printf("%c%c%c\n",i,j,k);

                        int res = 0;
                        ff(i, 0, sz-1)
                            res += nwz[i];
                        printf("%d\n", res);
                }


            }
    return 0;
}
