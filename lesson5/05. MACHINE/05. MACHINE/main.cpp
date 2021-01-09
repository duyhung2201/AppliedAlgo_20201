//
//  main.cpp
//  05. MACHINE
//
//  Created by Duy Hung Le on 01/12/2020.
//

#include <iostream>
using namespace std;

int n, a[2000001], res=-1;

int main() {
    for (int i=1; i<=2e6; i++) a[i]=-1;
    ios_base::sync_with_stdio(0);
    cin >> n;
    int s[n], t[n];
    for (int i=0; i<n; i++){
        cin >> s[i] >> t[i];
        a[t[i]] = max(a[t[i]], t[i] - s[i]);
    }
    
    for (int i=1; i <=2e6; i++) a[i] = max(a[i], a[i-1]);
    
    for (int i=0; i<n; i++){
        if (a[s[i]-1] >0)
            res = max(res, t[i] - s[i] + a[s[i]-1]);
    }
    
    cout << res << endl;
}
