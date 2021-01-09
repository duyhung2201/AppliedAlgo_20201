#include <iostream>
#include <fstream>
using namespace std;

int n, k, cost[23][23], best = 2e9, cminPick = 2e9, cminDrop = 2e9, mark[23], occupy = 0;

void solution(int p, int curCost, int curPos)
{
    if (p > 2 * n)
    {
        best = min(best, curCost + cost[curPos][0]);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0 && occupy < k && curCost + cminPick * (2 * n + 1 - p) + cost[curPos][i] < best)
        {
            occupy++;
            mark[i] = 1;
            solution(p + 1, curCost + cost[curPos][i], i);
            mark[i] = 0;
            occupy--;
        }
        else if (mark[i] == 1 && curCost + cminDrop * (2 * n + 1 - p) + cost[curPos][n + i] < best)
        {
            occupy--;
            mark[i] = 2;
            solution(p + 1, curCost + cost[curPos][n + i], n + i);
            mark[i] = 1;
            occupy++;
        }
    }
}

int main()
{
    ifstream myfile;
    myfile.open("/Users/apple/Library/Mobile Documents/com~apple~CloudDocs/HUST-20201/AppliedAlgo-20201/example.txt");
    char data[100];
    myfile >> n >> k;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            myfile >> cost[i][j];
            if (i == j)
            {
                continue;
            }
            if (j <= n)
            {
                cminPick = min(cost[i][j], cminPick);
            }
            else
            {
                cminDrop = min(cost[i][j], cminDrop);
            }
        }
    }
    solution(1, 0, 0);
    cout << best;
    myfile.close();
}