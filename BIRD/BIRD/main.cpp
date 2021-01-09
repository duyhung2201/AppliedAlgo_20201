//
//  main.cpp
//  CONNECTED COMPONENTS
//
//  Created by Duy Hung Le on 11/12/2020.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[2000];
vector<int> color(2000, -1);
int N, M;

void dfs(int col, int u)
{
    if (color[u] != -1)
        return;
    color[u] = col;

    // for (int y : adj[u])
    for (int i = 0; i < adj[u].size(); i++)
    {
        dfs(1 - col, adj[u][i]);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Scenario #" << t << ":" << endl;
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            adj[i].clear();
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= N; i++)
            color[i] = -1;
        for (int i = 1; i <= N; i++)
            if (color[i] != -1)
                dfs(0, i);
        int ok = 1;
        for (int i = 1; i <= N && ok == 1; i++)
            for (int j = 0; j < adj[i].size(); j++)
                if (color[i] == color[j])
                {
                    int ok = 0;
                    break;
                }
        if (ok == 1)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
    }

    return 0;
}
