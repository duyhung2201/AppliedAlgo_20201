#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[100001], low(100001), num(100001, -1), bridge[100001];
bool visited[100001];
int curNum = 0;

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addBridge(int u, int v)
{
    bridge[u].push_back(v);
    bridge[v].push_back(u);
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
                addBridge(u, v);
            }
        }
    }
}

int dfs(int u)
{
    int res = 1;
    visited[u] = true;
    for (int i = 0; i < bridge[u].size(); i++)
    {
        int v = bridge[u][i];
        if (!visited[v])
            res += dfs(v);
    }
    return res;
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

    for (int u = 1; u <= n; u++)
    {
        if (num[u] == -1)
            findBridges(u, -1);
    }

    long long ans = 0;
    for (int u = 1; u <= n; u++)
    {
        if (!bridge[u].empty() && !visited[u])
        {
            int vertCnt = dfs(u);
            ans += 1ll * vertCnt * (vertCnt - 1) / 2 - vertCnt + 1;
        }
    }

    cout << ans;

    return 0;
}
