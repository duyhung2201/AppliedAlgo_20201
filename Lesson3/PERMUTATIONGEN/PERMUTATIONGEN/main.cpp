#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k, fac[10001];
bool mark[10001], isSolved=false;

int getPosition(int x){
    int t=0;
    for (int i=1;i<=n;i++){
        if(!mark[i]){
            t++;
        }
        if(t==x){
            mark[i]=true;
            return i;
        }
    }
    return 0;
}

void soltution(int p) {
    if (p>n){
        isSolved=true;
        return;
    }
    int x = k/fac[n-p];
    k%=fac[n-p];
    if(k==0){
        k=fac[n-p];
    }
    else {
        x++;
    }
    cout << getPosition(x) << " ";
    
    soltution(p+1);
}

int main()
{
    cin >> n  >> k;

    fac[0]=1;
    for(int i=1;i<=n;i++){
        if ( i > 12) fac[i]= INT_MAX;
        else fac[i]=i*fac[i-1];
    }
    if (k >= fac[n]) {
        cout << -1;
        return 0;
    }
    soltution(1);
    if (!isSolved){
        cout << -1;
    }
    return 0;
}
