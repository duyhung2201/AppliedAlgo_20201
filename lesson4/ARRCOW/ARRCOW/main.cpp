//
//  main.cpp
//  ARRCOW
//
//  Created by Duy Hung Le on 11/6/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;

bool check(int k, vector<int> x){
    int i = 0;
    for (int t=1; t<=C; t++){
        if (i >= N ) return false;
        int preStall = x[i];
        while (x[i]-preStall < k && i < N && t<C) i++;
    }
    
    return true;
}

int binarySearch(int L, int H, vector<int> x, int ans) {
    if (L > H) return ans;
    int mid = (L+H)/2;
    if (check(mid, x))
        return binarySearch(mid+1, H, x, mid);
    else
        return binarySearch(L, mid-1, x, ans);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin >> T;
    
    for (int t=1; t<=T; t++){
        cin >> N >> C;
        vector<int> x(N);
        for (int &e: x) cin >> e;
        sort(x.begin(), x.end());
        
        cout << binarySearch(1, x.back()- x.front(), x, 1) << endl;
    }
    
    return 0;
}
