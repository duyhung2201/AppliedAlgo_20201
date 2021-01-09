//
//  main.cpp
//  BACP
//
//  Created by Duy Hung Le on 11/2/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
using namespace std;

int N, M, c[17], pre[17][17], assign[17], load[6], res=2e9;

int maxLoad() {
    int temp =0;
    for (int m=1;m <=M; m++){
        temp= max(temp, load[m]);
    }
    return temp;
}

bool check(int k) {
    for (int i=1;i <=k; i++){
        for (int j=1;j<=k;j++){
            if(pre[i][j]==1 && assign[i] >= assign[j]){
                return false;
            }
        }
    }
    return true;
}

void Try(int k) {
    if (k>N){
        res = min(res, maxLoad());
        return;
    }
    for (int m=1;m<=M;m++){
        if(maxLoad() < res){
            load[m]+=c[k];
            assign[k]=m;
            if(check(k)) Try(k+1);
            load[m]-=c[k];
        }
    }
}

int main() {
    cin >> N >> M;
    
    for (int i=1; i<=N; i++){
        cin >> c[i];
    }
    for (int i=1;i <=N; i++){
        for (int j=1;j<=N;j++){
            cin >> pre[i][j];
        }
    }
    Try(1);
    
    cout << res;
    return 0;
}
