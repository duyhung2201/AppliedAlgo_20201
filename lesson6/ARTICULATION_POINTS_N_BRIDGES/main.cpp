#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001], low(100001), num(100001, -1), bridge[100001];
int curNum = 0, bridgeCnt, artCnt;
bool isArticulation[100001];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void findBridges(int u, int p)
{
    low[u] = num[u] = ++curNum;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v != p)
        {
            if (num[v] == -1)
            {
                findBridges(v, u);
                low[u] = min(low[u], low[v]);
            }
            else
            {
                low[u] = min(low[u], num[v]);
            }
            if (low[v] > num[u])
            {
                cout << u << " - " << v << endl;
                bridgeCnt++;
                artCnt += ((isArticulation[u]) ? 0 : 1) +
                          ((isArticulation[v]) ? 0 : 1);
                isArticulation[u] = isArticulation[v] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (num[i] == -1)
            findBridges(i, -1);
    }

    cout << artCnt << " " << bridgeCnt;

    return 0;
}