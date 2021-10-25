#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;

struct Team {
    ll score;
    int num;
    int best;
    int worst;
}team[500005];
ll b[500005];
bool cmp1(Team t, Team a)
{
    return t.score > a.score;
}
bool cmp2(Team t, Team a)
{
    return t.num < a.num;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> team[i].score;
            team[i].num = i;
            team[i].best = 1;
            team[i].worst = n;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        sort(team + 1,team + n + 1, cmp1);
        for (int i = 1; i <= n; i++)
        {
            
                int tempn = 0;
                ll temps = team[i].score + b[1];
                for (int k = 1; k < i; k++)
                {
                    if (team[k].score + b[n - tempn] <= temps)
                    {
                        tempn++;

                    }
                    else
                    {
                        team[i].best++;
                    }
            
                
                }
        }
        for (int i = n; i >=1; i--)
        {
            int tempn = 0;
            ll temps = team[i].score + b[n];
            for (int k = n;team[k].score<=team[i].score&&k>=1; k--)
            {
                if (k == i)
                    continue;
                if (team[k].score + b[1 + tempn] > temps)
                {
                    tempn++;
                }
                else
                {
                    team[i].worst--;
                }
            }
        }
        sort(team + 1, team + n + 1, cmp2);
        for (int i = 1; i <= n; i++)
            cout << team[i].best <<" "<<team[i].worst << "\n";
    }
}
