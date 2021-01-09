//
//  main.cpp
//  05. WAREHOUSE
//
//  Created by Duy Hung Le on 27/11/2020.
//

#include <iostream>
using namespace std;

int N, T,D, a[1001], t[10001], mem[10001][101], res = 0;

int f(int i, int k) {
    if (k < t[i]) return 0;
    if (mem[i][k] != -1) return mem[i][k];
    
    int ans = a[i];
    for (int j=i-1; j>=i-D && j >=1; j--){
        ans = max(ans, f(j, k-t[i]) + a[i]);
    }
    mem[i][k] = ans;
    return ans;
}

int main() {
    cin >> N >> T >> D;
    for (int i=1; i<= N; i++) cin >> a[i];
    for (int i=1; i<= N; i++) cin >> t[i];
    
    for (int i=1; i<=N; i++){
        for (int j=1; j<=T; j++){
            mem[i][j] = -1;
        }
    }
    
    for (int i=N; i>=1; i--) res = max(res, f(i, T));
    
    cout << res;
    return 0;
}
