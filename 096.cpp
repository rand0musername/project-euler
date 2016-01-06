// RandomUsername (Nikola Jovanovic)
// Project Euler
// 096

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(lld i=a; i<=b; i++)
#define fb(i,a,b) for(lld i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000000000000LL
#define MAXN 10005

using namespace std;

struct board
{
    bool tmp[10];
    int a[10][10];
    pair<int, bool> FindMaxUnsolved() //isRow?
    {
        int bestIdx = -1;
        bool bestIdxIsRow = true;
        int best = -1;

        ff(i, 1, 9)
        {
            if(a[i][0] < 9 && a[i][0] > best)
            {
                best = a[i][0];
                bestIdx = i;
                bestIdxIsRow = true;
            }
        }

        ff(j, 1, 9)
        {
            if(a[0][j] < 9 && a[0][j] > best)
            {
                best = a[0][j];
                bestIdx = j;
                bestIdxIsRow = false;
            }
        }

        if(bestIdx == -1)
            return par({bestIdx, bestIdxIsRow});

        ff(i, 0, 9)
            tmp[i] = false;
        ff(it, 1, 9)
            if(bestIdxIsRow)
                tmp[ a[bestIdx][it] ] = true;
            else
                tmp[ a[it][bestIdx] ] = true;

        return par({bestIdx, bestIdxIsRow});
    }
    void Set(int i, int j, int val)
    {
        a[i][j] = val;
        a[i][0]++;
        a[0][j]++;
    }
    void Reset(int i, int j)
    {
        a[i][j] = 0;
        a[i][0]--;
        a[0][j]--;
    }
};

board n;
char pom[15];
int ret;

void Print(board n)
{
        cout<<"0|";
        ff(j, 1, 9)
        {
            cout<<n.a[0][j];
        }
        cout<<endl;
        ff(j, 0, 10)
        {
            cout<<'-';
        }
        cout<<endl;
        ff(i, 1, 9)
        {
            cout<<n.a[i][0]<<"|";
            ff(j, 1, 9)
            {
                cout<<n.a[i][j];
            }
            cout<<endl;
        }
        cout<<"Woo!"<<endl;
}

int f(int x)
{
    return x - (x-1)%3;
}

int Solve(board n)
{
    pair<int, bool> curr = n.FindMaxUnsolved();
    int idx2, result;

    if(curr.fi == -1)
    {
        //solved it
        return n.a[1][1]*100 + n.a[1][2]*10 + n.a[1][3];
    }

    if(curr.se)
    {
        //row
        ff(j, 1, 9)
        {
            if(n.a[curr.fi][j] == 0)
                {idx2 = j; break;}
        }
        ff(num, 1, 9)
        {
            if(!n.tmp[num])
            {
                bool ok = true;
                ff(i, 1, 9)
                    if(n.a[i][idx2] == num)
                        ok = false;
                ff(i, f(curr.fi), f(curr.fi)+2)
                    ff(j, f(idx2), f(idx2)+2)
                        if(n.a[i][j] == num)
                            ok = false;
                if(!ok) continue;
                n.Set(curr.fi, idx2, num);
                result = Solve(n);
                if(result)
                    return result;
                else
                    n.Reset(curr.fi, idx2);
            }
        }
    }
    else
    {
        //column
        ff(i, 1, 9)
        {
            if(n.a[i][curr.fi] == 0)
                {idx2 = i; break;}
        }
        ff(num, 1, 9)
        {
            if(!n.tmp[num])
            {
                bool ok = true;
                ff(j, 1, 9)
                    if(n.a[idx2][j] == num)
                        ok = false;
                ff(i, f(idx2), f(idx2)+2)
                    ff(j, f(curr.fi), f(curr.fi)+2)
                        if(n.a[i][j] == num)
                            ok = false;
                if(!ok) continue;
                n.Set(idx2, curr.fi, num);
                result = Solve(n);
                if(result)
                    return result;
                else
                    n.Reset(idx2, curr.fi);
            }
        }
    }
    return 0;
}

int main()
{
    freopen("096.in", "r", stdin);
    ff(it, 1, 50)
    {
        ff(i, 1, 9)
            n.a[i][0] = n.a[0][i] = 0;

        scanf("%s %s", pom, pom);
        ff(i, 1, 9)
        {
            scanf("%s", pom);
            ff(j, 1, 9)
            {
                n.a[i][j] = pom[j-1] - '0';
                if(n.a[i][j] > 0)
                {
                    n.a[i][0]++;
                    n.a[0][j]++;
                }
            }
        }
        ret += Solve(n);
    }
    printf("%d\n", ret);
    return 0;
}
