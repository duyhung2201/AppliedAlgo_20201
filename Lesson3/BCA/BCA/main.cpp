//
//  main.cpp
//  BCA
//
//  Created by Duy Hung Le on 10/30/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
using namespace std;

int N, M, con[31][31], pref[11][31], best = -1, teach[31], load[11], teacherCon[11][31];

int f() {
    int maxLoad =0;
    for (int i=1;i<=M;i++) {
        load[i] =0;
    }
    for (int i=1;i <=N;i++) {
        load[teach[i]]++;
    }
    for (int i=1;i<=M;i++) {
        maxLoad = max(load[i], maxLoad);
    }
    return maxLoad;
}

void Try(int k){
    if (k> N){
        for (int i=1; i<=N;i++){
            if (!teach[i]){
                return;
            }
        }
        
        best = (best == -1) ? f() : min(best, f());
        return;
    }
    for (int m=1;m <=M; m++){
        int maxLoad = f();
        if (teacherCon[m][k]==0 && pref[m][k] && maxLoad < (best==-1? 2e9: best)) {
            for (int i=1; i<=N; i++){
                teacherCon[m][i]+=con[k][i];
            }
            teach[k]=m;
            Try(k+1);
            for (int i=1; i<=N; i++){
                teacherCon[m][i]-=con[k][i];
            }
            teach[k]=0;
        }
    }
    
}

int main() {
    cin >> M >> N;
    int k;
    for (int i=1; i<=M;i++){
        cin >> k;
        for (int j=1; j<=k;j++){
            int t;
            cin >> t;
            pref[i][t] = 1;
        }
    }
    
    cin >> k;
    for (int h =1; h<=k; h++){
        int i,j;
        cin >> i>> j;
        con[i][j] = 1;
        con[j][i] = 1;
    }
    
    Try(1);
    cout << best;
    return 0;
}
