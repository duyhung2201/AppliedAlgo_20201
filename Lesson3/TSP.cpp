#include <iostream>
using namespace std;

int n, cost[21][21], best = 2e9, a[21], cmin = 2e9;
bool mark[21];

void solution(int k, int curCost)
{
    if (k > n)
    {
        if (cost[a[n]][1] != -1 && curCost + cost[a[n]][1] < best)
        {
            best = curCost + cost[a[n]][1];
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!mark[i] && cost[a[k - 1]][i] != -1 && curCost + cost[a[k - 1]][i] + cmin * (n + 1 - k) < best)
        {
            a[k] = i;
            mark[i] = true;
            solution(k + 1, curCost + cost[a[k - 1]][i]);
            mark[i] = false;
        }
    }
}

int main()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (i == j)
            {
                cost[i][j] = 0;
            }
            else
            {
                cost[i][j] = -1;
            }
        }
        mark[i] = false;
    }
    a[1] = 1;

    int m;
    cin >> n >> m;
    for (int k = 0; k < m; k++)
    {
        int i, j, c;
        cin >> i >> j;
        cin >> cost[i][j];
        cmin = cost[i][j] < cmin ? cost[i][j] : cmin;
    }
    solution(2, 0);
    cout << best;
}