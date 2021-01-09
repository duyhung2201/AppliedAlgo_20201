//
//  main.cpp
//  05. NURSE
//
//  Created by Duy Hung Le on 04/12/2020.
//

#include <iostream>
using namespace std;

int N, K1, K2, mem[1001], mod = 1e9+7;

int dp(int i){
    if (i >= N)
        return 1;
    if (mem[i] != -1) return mem[i];
    int ans =0;
    for (int x=K1; x <= K2 && i+x<=N; x++)
        ans+=dp(i+x+1);
    mem[i]=ans;
    
    return ans;
}

int main() {
    cin >> N >> K1 >> K2;
    for(int i=0; i<=N; i++) mem[i] = -1;
    int res = dp(0) + dp(1);
    
    cout << res;
    return 0;
}
