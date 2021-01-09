//
//  main.cpp
//  CONNECTED COMPONENTS
//
//  Created by Duy Hung Le on 11/12/2020.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
vector<int> component(100001, -1);
int N,M;

void find_component(int cur, int u){
    if (component[u] != -1) return;
    component[u] = cur;
    
    for (int i=0; i< adj[u].size(); i++){
        find_component(cur, adj[u][i]);
    }
    
}

int main() {
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int componentCnt = 0;
    for (int i=1; i<=N; i++){
        if (component[i] == -1){
            find_component(componentCnt, i);
            componentCnt++;
        }
    }
    
    cout << componentCnt;
    return 0;
}
