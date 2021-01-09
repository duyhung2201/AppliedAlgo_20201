//
//  main.cpp
//  EKO
//
//  Created by Duy Hung Le on 11/9/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;

bool check(int h, vector<int> a){
    long long sum = 0;
    for (int i=0; i<a.size(); i++){
        sum += (h < a[i] ? a[i]-h: 0);
    }
    
    return sum >= M;
}

int binarySearch(int L, int H, vector<int> a, int ans) {
    if (L > H) return ans;
    int mid = (L+H)/2;
    
    if (check(mid, a))
        return binarySearch(mid+1, H, a, mid);
    else
        return binarySearch(L, mid - 1, a, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >>M;
    vector<int> a(N);
    int maxHeight = 0;
    for (int &e: a) {
        cin >> e;
        maxHeight = max(maxHeight, e);
    }
    
    cout << binarySearch(0, maxHeight - 1, a, -1);
    
    return 0;
}
