//
//  main.cpp
//  INCREASE SUBSEQ
//
//  Created by Duy Hung Le on 21/11/2020.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], best[n], res = 0;
    
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    
    for (int i = 0; i < n; i++){
        best[i] = 1;
        for (int  j =i-1 ;j >=0; j--){
            if (a[i] > a[j]){
                best[i] = max(best[i], best[j] + 1);
                res = max(best[i], res);
            }
        }
    }
    
    cout << res  << endl;
    
    return 0;
}
