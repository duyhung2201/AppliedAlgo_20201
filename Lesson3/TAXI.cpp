#include <iostream>
using namespace std;

int n, cost[23][23], best = 2e9, mark[11], cmin = 2e9;

void solution(int k, int curCost, int curPos)
{
    if (k > n)
    {
        best = min(curCost + cost[curPos][0], best);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0 && curCost + cmin * ((n + 1 - i) * 2 + 1) < best)
        {
            mark[i] = 1;
            solution(k + 1, curCost + cost[curPos][i] + cost[i][i + n], i + n);
            mark[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int k = 0; k < 2 * n + 1; k++)
    {
        for (int l = 0; l < 2 * n + 1; l++)
        {
            cin >> cost[k][l];
            cmin = min(cost[k][l], cmin);
        }
    }
    solution(1, 0, 0);
    cout << best;
}