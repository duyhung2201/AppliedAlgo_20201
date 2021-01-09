//
//  main.cpp
//  HTMAX
//
//  Created by Duy Hung Le on 18/12/2020.
//

#include <iostream>
using namespace std;

int n, a[100001], mem[100001], id[100001], cntId = 0, res =0;

int f(int k, int cnt){
    if (k>n) {
        return 0;
    }
    if (a[k] <= 0) return f(k+1, cnt);
    if (mem[k] != -1) return mem[k];
    
    int res1 = a[k] + f(k+2, cnt + 1);
    int res2 = a[k+1] + f(k+3, cnt + 1);
    
    if (res1 < res2) {
        mem[k+1] = res2;
        return res2;
    } else {
        mem[k] = res1;
        return res1;
    }
}

void trace(int i) {
    int t = i;
    while (mem[t] != res && t<=n) t++;
    if (t > n) {
        return;
    }
    cntId++;
    id[cntId] = t;
    res-=a[t];
    if (t+2 <= n) trace(t+2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        mem[i] = -1;
    }
    
    res = f(1, 0);
    cout << res << endl;
    trace(1);
    cout << cntId << endl;
    for (int i=1; i<=cntId; i++) cout << id[i] << " ";
    return 0;
}
/*
5
1 1 3 2 1
*/
