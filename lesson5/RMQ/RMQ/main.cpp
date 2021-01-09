//
//  main.cpp
//  RMQ
//
//  Created by Duy Hung Le on 21/11/2020.
//

#include <iostream>
using namespace std;



int minOfSeq(int i, int j, int a[], int M[][23]) {
    if (i==j) return M[i][0];
//    if (M[i])
    
    return 0;
}

int main() {
    int n,m, sum=0;
    cin >> n;
    int a[n], M[n][23];
    for (int i =0; i<n;i++){
        cin >> a[i];
        M[i][0]=a[i];
    }
    cin >> m;
    
    for (int t=0; t<m;t++){
        int i , j;
        cin >> i >> j;
//        sum += minOfSeq(i, j);
        
    }
    
}
