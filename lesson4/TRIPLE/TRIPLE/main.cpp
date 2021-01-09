//
//  main.cpp
//  TRIPLE
//
//  Created by Duy Hung Le on 11/6/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, res=0;
    cin >> N >> K;
    vector<int> a(N);
    for (auto &x: a) cin >> x;
    vector<int> cnt(100001);
    
    for (int j=1; j < N-1; j++){
        cnt[a[j-1]]++;
        for (int k=j+1; k< N; k++){
            int t = K - a[j]- a[k];
            if (t >= 0) {
                res+= cnt[t];
            }
        }
    }
    
    cout << res;
    return 0;
}
