#include <iostream>
using namespace std;

int n, K, Q, d[11], m[6], r[6][13], res = 2e9, dis[13][13], bestDis[6];
bool mark[13];

void bestSum(int p, int k, int curSum,int curPos)
{
    if (p > r[k][0])
    {
        bestDis[k]=min(curSum+dis[curPos][0],bestDis[k]);
        return;
    }
    for (int i = 1; i <= r[k][0]; i++)
    {
        if(!mark[r[k][i]])
        {
            mark[r[k][i]] = true;
            bestSum(p + 1, k, curSum + dis[curPos][r[k][i]], r[k][i]);
            mark[r[k][i]] = false;
        }
    }
}

void solution(int p)
{
    if (p > n)
    {
        for (int k = 1; k <= K; k++)
        {
            if (r[k][0] == 0)
            {
                return;
            }
        }
        int sum = 0;
        for (int k = 1; k <= K; k++)
        {
                bestDis[k]=2e9;
                bestSum(1, k, 0, 0);
                sum += bestDis[k];
        }
        
        res = min(res,sum);
        return;
    }
    for (int k = 1; k <= K; k++)
    {
        if (m[k] + d[p] <= Q)
        {
            m[k] += d[p];
            r[k][0]++;
            r[k][r[k][0]] = p;
            solution(p + 1);
            m[k] -= d[p];
            r[k][r[k][0]] = 0;
            r[k][0]--;
        }
    }
}

int main()
{
    cin >> n >> K >> Q;
        
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n;j++){
            cin >> dis[i][j];
        }
    }
    
    solution(1);
    
    cout << res;
    cout << d[12];
}

//11 4 33
//12 20 4 15 18 8 4 14 9 7 13
//0 14 11 11 11 13 12 14 12 10 14 10
//11 0 10 13 13 14 14 13 11 14 10 13
//12 13 0 10 14 11 11 14 10 11 11 11
//11 11 10 0 12 11 13 10 14 11 10 13
//11 10 12 13 0 14 14 11 14 11 10 10
//12 13 11 12 14 0 14 11 13 10 11 10
//12 12 10 10 11 12 0 10 14 13 10 12
//12 11 13 12 13 13 13 0 11 10 14 11
//11 11 13 13 13 14 13 13 0 12 11 10
//14 13 14 11 14 13 10 10 11 0 13 10
//13 12 13 12 14 14 14 14 10 11 0 12
//13 12 14 13 13 13 13 11 13 14 11 0

//164
