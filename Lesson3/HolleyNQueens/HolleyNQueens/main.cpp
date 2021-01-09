//
//  main.cpp
//  HolleyNQueens
//
//  Created by Duy Hung Le on 11/12/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
using namespace std;

int N, M, mark[13][13], sum=0;

void placeQueen(int r, int c, int x){
    for (int i =1; i<=N; i++){
        mark[r][i] += x;
        if (1<= r+ (c-i) && r+ (c-i) <= N){
            mark[r+ (c-i)][i] +=x;
        }
        if (1<= r- (c-i) && r- (c-i) <= N){
            mark[r- (c-i)][i] +=x;
        }
    }
}

void Try(int k){
    if (k > N){
        sum++;
        return;
    }
    for (int i =1; i<=N; i++){
        if (mark[i][k]==0){
            placeQueen(i, k, 1);
            Try(k+1);
            placeQueen(i, k, -1);
        }
    }
    
}

void reset() {
    for (int i=1; i<=N; i++){
        for (int j =1; j<=N; j++) {
            mark[i][j]=0;
        }
    }
    sum = 0;
}

int main() {
    ios::sync_with_stdio(false);
    while (true){
        cin >> N >> M;
        if (N==M && M==0) break;
        reset();
        for (int m=0; m<M; m++){
            int r,c;
            cin >> r >> c;
            mark[r][c]=1;
        }
        
        Try(1);
        cout << sum << endl;
    }
    return 0;
}
