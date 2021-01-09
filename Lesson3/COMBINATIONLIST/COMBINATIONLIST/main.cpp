#include <iostream>
#include <algorithm>
using namespace std;

int n, m, C[10001];
bool isSolved =false;

void printArray(int size){
    for (int i=1; i<=size; i++){
        cout << C[i] << " ";
    }
    cout  << endl;
}

void Try(int k) {
    if(k>m){
        isSolved=true;
        return;
    }
    C[k]=C[k-1]+1;
    Try(k+1);
}


int main()
{
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> C[i];
    }
    for (int i = m; i>0; i--){
        if (n-m+i == C[i]) {
            continue;
        }
        else {
            Tr
        }
    }
    Try(1);
    if(!isSolved){
        cout << -1;
    }
}
