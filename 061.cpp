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
#define MAXN 100000005
#define MOD 1000000007

using namespace std;

int M[10][100][100];
bool is[10][10000];
vector<int> perm = {3, 4, 5, 6, 7, 8};
int tmp[10][100][100];

void matmul(int a[100][100], int b[100][100], int c[100][100]) {
    ff (i, 10, 99) {
        ff (j, 10, 99) {
            c[i][j] = 0;
            ff (k, 10, 99) {
                if (i == 0 && k == 0) continue;
                if (j == 0 && k == 0) continue;
                int curr = a[i][k] * b[k][j];
                if (curr > 0) {
                    if (i == 28)
                    cout << "We can stitch " << i << "->" << k << " and " << k << "->" << j << endl;
                }
                c[i][j] += curr;
            }
            c[i][j] = min(c[i][j], 1);
        }
    }
}

// Testing
int main()
{
    int TOTAL = 0;

    cout << "Triangles: " << endl;
    ff (n, 1, 1000) {
        int m = n * (n + 1) / 2;
        if (m <= 9999) {
            is[3][m] = true;
            cout << m << endl;
        }
        m = n * n;
        if (m <= 9999) is[4][m] = true;
        m = n * (3*n - 1) / 2;
        if (m <= 9999) is[5][m] = true;
        m = n * (2*n - 1);
        if (m <= 9999) is[6][m] = true;
        m = n * (5*n - 3) / 2;
        if (m <= 9999) is[7][m] = true;
        m = n * (3*n - 2);
        if (m <= 9999) is[8][m] = true;
    }

    ff (n, 0, 99) {
        ff (m, 0, 99) {
            ff (i, 3, 8) {
                M[i][n][m] = is[i][n * 100 + m];
            }
        }
    }

    do {
        cout << "Trying a new perm: ";
        ff (i, 0, 5) {
            cout << perm[i] << " ";
        }
        cout << endl; 

        // try matrices with this perm
        ff (i, 0, 4) {
            if (i == 0) {
                matmul(M[perm[5]], M[perm[0]], tmp[0]);
            } else {
                matmul(tmp[i-1], M[perm[i]], tmp[i]);
            }

           cout << "Checks at iteration " << i << " after doing " << perm[i] << endl;
            ff (ii, 28, 28) {
                ff (jj, 0, 99) {
                    if (tmp[i][ii][jj]) {
                       cout << "ONE AT: " << ii << " " << jj << endl;
                    }
                }
            }

        }
        cout<<"Fin"<<endl;

        // does tmp[5] have a single good entry AT DIAGONAL
        ff (i, 0, 99) {
            if (tmp[4][i][i]) {
                cout << "WIN: " << i << " " << i << endl;
                TOTAL += 1;
                return 0;
            }
        }

       // return 0;

    } while (next_permutation(perm.begin(), perm.end()));

    cout << "TOTAL SOLS: " << TOTAL << endl;

    return 0;
}


// 28 82 56 25 12 81