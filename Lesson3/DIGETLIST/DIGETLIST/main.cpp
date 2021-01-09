//
//  main.cpp
//  DIGETLIST
//
//  Created by Duy Hung Le on 11/13/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
using namespace std;

int n,i,k, a[10001], count0;
bool isSolvable = false;

void Try (int t){
    if (t > n) {
        k--;
        if (k==0)
            isSolvable=true;
        return;
    }
    //    a[t]=0
    if (count0>1){
        count0--;
        a[t]=0;
        Try(t+1);
        if (isSolvable) return;
        count0++;
    }
    //    a[t]=1
    a[t]=1;
    int temp = count0;
    count0=i;
    Try(t+1);
    if (isSolvable) return;
    count0=temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> i;
    count0=i;
    Try(1);
    if (isSolvable){
        for (int t=1; t<=n; t++){
            cout << a[t] << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}
