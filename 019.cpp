// RandomUsername (Nikola Jovanovic)
// Project Euler
// 019

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
#define MAXN 2000005

using namespace std;

// Tryhard

int day, month, year;
int weekday; //1 - 7

int dpm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int leapAdd()
{
    if(month != 2) return 0;
    if(year % 4 != 0) return 0;
    if(year % 100 == 0 && year % 400 != 0) return 0;
    return 1;
}

void Next()
{
    //adjust weekday
    weekday++; if(weekday == 8) weekday = 1;
    //adjust day
    day++;
    if(day > dpm[month] + leapAdd())
    {
        day = 1;
        month++;
        if(month == 13)
        {
            month = 1;
            year++;
        }
    }
}

int main()
{
    int ret = 0;

    day = 1, month = 1, year = 1901, weekday = 2;
    while(year <= 2000)
    {
        if(weekday == 7 && day == 1)
            ret++;
        Next();
    }
    cout<<ret<<endl;
    return 0;
}
