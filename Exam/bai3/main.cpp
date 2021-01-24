#include <bits/stdc++.h>
using namespace std;

int a[51], n, ans = 0, dis[51][51], Q;
bool d[51];

// int Try(int k){
//     if (k==n){

//     }
//     for (int i=1; i<=n; i++){
//         if (!d[i]){

//         }
//     }
// }

int main()
{
    // freopen("../../exam3/VD4/GROUPUP.inp", "r", stdin);
    
        ans = 0;
        cin >> n >> Q;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            d[i]=false;
        }
        for (int i = 0; i<=n; i++){
            for (int j=0; j<=n; j++)
                cin >> dis[i][j];
        }
        cout << ( std::rand() % ( 1000000000000 ) ) << endl;
        int t = std::rand() % ( n );
        cout <<  t << endl;
        for (int i=1; i<=t; i++){
            cout << i << " ";
        }
        

    return 0;
}