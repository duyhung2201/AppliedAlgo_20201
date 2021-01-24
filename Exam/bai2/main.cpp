#include <bits/stdc++.h>
using namespace std;

int T, a[100001], mem[100001], n;
map<int, vector> ind;

int f(int k){
    if (k==0){ 
        mem[k]=1;
        return 1;
    }
    if (mem[k]!=-1) return mem[k];

    int res =1;
    // for (int i=k-1; i>=0; i--){
    //     if(a[i]==a[k]-1) {
    //         res+=f(i);
    //         break;
    //     }
    // }
    if (ind.find(a[k] - 1) != ind.end()) {
        int t = ind[a[k] - 1];
        res+=f(t);
    }

    mem[k]=res;
    return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
    // freopen("../../VD5/LISS1.inp", "r", stdin);
    cin >> T;
    while (T--)
    {   
        memset(mem, -1, sizeof(mem));
        ind = map<int,int>();
        int res=0;
        cin >> n;
        for (int i=0; i<n; i++){
             cin >> a[i];
             ind[a[i]].insert()
        }

        for (int i=n-2 ;i>=0; i--){
             ind[a[i]]=i;
            res = max(res, f(i));
        }

        cout << res << endl;
    }

    return 0;
}