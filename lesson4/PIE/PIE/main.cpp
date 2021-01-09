//
//  main.cpp
//  PIE
//
//  Created by Duy Hung Le on 11/15/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N,F;
double pii = 2*acos(0.0);
double maxArea;
double unit = 1e-6;

bool check(vector<int> r, double sizeP){
    int frCnt =0;
    for (int i=0; i< N; i++){
        frCnt += (int)((pii*r[i]*r[i])/sizeP);
    }
    return frCnt >= F+1;
}

double binaryS(vector<int> r ,double L, double H, double ans) {
    if (H - L < unit)
        return ans;
    double mid = (L+H)/2;
    if (check(r, mid))
        return binaryS(r, mid, H, mid);
    else
        return binaryS(r, L, mid, ans);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=0; t<T; t++){
        cin >> N >> F;
        vector<int> r(N);
        int maxR = 0;
        for (int &e: r) {
            cin >> e;
            maxR = max(e,maxR);
        }
        maxArea = pii*maxR*maxR;
        
        printf("%.6f\n", binaryS(r, 0, maxArea, -1));
    }
    return 0;
}
