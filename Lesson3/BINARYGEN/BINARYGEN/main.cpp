//
//  main.cpp
//  BINARYGEN
//
//  Created by Duy Hung Le on 11/6/20.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
using namespace std;

int C[10001] , a[10001], n;
bool isNext, isSolved;

void Try(int k){
    if (k>n) {
        if (!isNext){
            isNext=true;
        } else {
            isSolved=true;
            for (int i=1;i<=n;i++){
                cout << a[i];
            }
            cout << endl;
        }
        
        return;
    }
    for (int i=0; i<=1;i++){
        if(C[k]==i || isNext){
            a[k]=i;
            Try(k+1);
            if (isSolved){
                return;
            }
        }
    }
}



int main() {
    cin >> n;
    for (int i=1;i <=n;i++){
        char a;
        cin >> a;
        C[i]= a - '0';
    }
    Try(1);
    if (!isSolved){
        cout << -1;
    }
    return 0;
}
