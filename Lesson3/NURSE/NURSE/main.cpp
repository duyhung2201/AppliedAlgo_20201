//
//  main.cpp
//  NURSE
//
//  Created by Duy Hung Le on 11/13/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
using namespace std;

int N, K1, K2, sum=0, mod = 1e9+7;

void Try(int r){
    if (r>=N) {
        if (r==N || r ==N+1) sum = (sum+1)%mod;
        return;
    }
    for (int k =K1; k<=K2; k++){
        Try(r+k+1);
    }
}

int main() {
    cin >> N>> K1>> K2;
    Try(0);
    Try(1);
    cout << sum;
    return 0;
}
