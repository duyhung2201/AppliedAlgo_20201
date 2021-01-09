//
//  main.cpp
//  CONNECTED COMPONENTS
//
//  Created by Duy Hung Le on 11/12/2020.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001];
vector<int> group(100001, 0);
bool isBiPartie = true;
int N,M;

int main() {
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> Q;
    Q.push(1);
    group[1] = 1;
    
    while (!Q.empty()){
        int u =Q.front();
        Q.pop();
        
        for (int i =0; i<adj[u].size(); i++){
            if (group[adj[u][i]] == 0) {
                Q.push(adj[u][i]);
                group[adj[u][i]] = group[u]*(-1);
            }
            else if (group[adj[u][i]] == group[u]) {
                cout << 0;
                return 0;
            }
        }
    }
    
    cout << 1;
    return 0;
}
