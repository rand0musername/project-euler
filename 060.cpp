// RandomUsername (Nikola Jovanovic)
// Sieve of Eratosthenes
// Finding all prime numbers: O( N )
// N - limit

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(long long i=a; i<=b; i++)
#define fb(i,a,b) for(long long i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 100000005
#define MOD 1000000007

using namespace std;

// comp[i] -> the number is composite
bool comp[MAXN];
int points[MAXN];
vector<lld> primes;

// Regular sieve for numbers [1..n]
void sieve(lld n)
{
    for(lld i = 1; i <= n; i++)
        comp[i] = false;
    comp[1] = true;
    for(lld i = 2; i <= n; i++)
    {
        lld j = i*i;
        if (!comp[i])  {
            primes.push_back(i);
            while (j <= n) {
                comp[j] = true;
                j += i;
            }
        }
    }
}

lld concat(lld x, lld y) {
    lld dig = 1;
    lld ret = 0;
    while (y > 0) {
        ret += dig * (y % 10);
        y /= 10;
        dig *= 10;
    }
    while (x > 0) {
        ret += dig * (x % 10);
        x /= 10;
        dig *= 10;
    }
    return ret;
}


vector<lld> niceprimes;

vector<pair<lld,lld>> starters;

// Testing
int main()
{
    // gen sieve
    lld n = 100000000;
    sieve(n);

    // gen a pair of "starters" that work 
    ff (i, 0, 1000) {
        ff (j, i+1, 1000) {
            if (comp[concat(primes[i], primes[j])]) continue;
            if (comp[concat(primes[j], primes[i])]) continue;
            starters.push_back({primes[i], primes[j]});
        }
    }
    for (auto x : starters) {
        cout << x.first << " " << x.second << endl; 
    }

    // for each pair of starters
    for (auto x : starters) {
        lld P = x.first;
        lld Q = x.second;
        cout << "TRYING STARTERS: " << P <<  " " << Q << endl;
        if (comp[concat(P, Q)]) { cout << "invalid" << endl; return 0;} 
        if (comp[concat(Q, P)]) { cout << "invalid" << endl; return 0;} 

        lld LIMIT = 10000;

        // filter out primes that work for these starters
        niceprimes.clear();

        for (lld p : primes) {
            if (p <= Q) continue;
            if (p >= LIMIT) break;
            if (comp[concat(p, P)]) continue;
            if (comp[concat(p, Q)]) continue;
            if (comp[concat(P, p)]) continue;
            if (comp[concat(Q, p)]) continue;
            niceprimes.push_back(p);
        }

        if (niceprimes.size() == 0) continue;

        // now we need to find triangles 
        ff (i, 0, niceprimes.size()-1) {
            if (niceprimes[i] > LIMIT) break;

            // first find all hits s.t. this is smallest
            vector<lld> localhits;
            ff (j, i+1, niceprimes.size()-1) {
                if (niceprimes[j] > LIMIT) break; 
                if (comp[concat(niceprimes[i], niceprimes[j])]) continue;
                if (comp[concat(niceprimes[j], niceprimes[i])]) continue;
                cout << "COMBO: " << niceprimes[i] << " and " << niceprimes[j] << endl;
                localhits.push_back(niceprimes[j]);
            }

            // can we close a triangle?
            if (localhits.size() == 0) continue; 
            cout << "investigating " << localhits.size() << " local hits" << endl;
            ff (i, 0, localhits.size()-1) {
                ff (j, i+1, localhits.size()-1) {
                    if (comp[concat(localhits[i], localhits[j])]) continue;
                    if (comp[concat(localhits[j], localhits[i])]) continue;
                    cout << "FINAL: " << localhits[i] << " and " << localhits[j] << endl;
                    lld answer = localhits[i] + localhits[j];
                    answer += niceprimes[i] + P + Q;
                    cout << "ANSWER = " << answer << endl;
                    return 0;
                }
                // is there a match between local hits?  
            }

        }
    }

    return 0;
}