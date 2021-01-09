//
//  main.cpp
//  FIBWORK
//
//  Created by Duy Hung Le on 20/11/2020.
//  Copyright © 2020 Macintosh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string f[2] = {"0", "1"}, p;
long long mem[102];

string subStr(unsigned long size, int n, bool atLast)
{
    if (n <= 1)
        return f[n];
    string ans = subStr(size, atLast ? n - 2 : n-1, atLast);
    if (ans.size() == size)
        return ans;
    return atLast ?
        subStr(size - ans.size(), n-1, atLast) + ans :
        ans + subStr(size - ans.size(), n-2, atLast);
}

unsigned long long cntOccurence(string p, string t)
{
    unsigned long long sum =0;
    for(long i=0; i<=(long)(t.size() - p.size()); i++){
        sum++;
        for (long j=0; j<p.size(); j++){
            if (p[j] != t[i+j]) {
                sum--;
                break;
            }
        }
    }
    return sum;
}

long long cnt(int n)
{
    if (n <= 1)
        return f[n] == p ? 1 : 0;
    if (mem[n] != -1) return mem[n];
    long long ans = cnt(n - 1) + cnt(n - 2);
    if (p.size() >1) {
        string t = subStr(p.size() - 1, n - 1, true) + subStr(p.size() - 1, n - 2, false);
        ans += cntOccurence(p, t);
    }
    mem[n] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t =0;
    while (cin >> n >> p) {
        for (int i=0; i<=100 ;i++) mem[i]=-1;
        cout << "Case " << ++t << ": " << cnt(n) << endl;
    }
}
