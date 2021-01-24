#include <bits/stdc++.h>
using namespace std;
int n, a[1000002], pre[1000002], nxt[1000002];

pair<int, int> p[1000001];
int compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    a[0] = a[n + 1] = 0;
    pre[0] = nxt[n + 1] = 0;
    nxt[0] = 1;
    pre[n + 1] = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = i - 1;
        nxt[i] = i + 1;
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p + 1, p + n + 1, compare);

    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = p[i].second;
        res += a[t] + a[pre[t]] + a[nxt[t]];
        pre[nxt[t]] = pre[t];
        nxt[pre[t]] = nxt[t];
    }

    cout << res;
}
/*
5 1 2 3 4 5
5 1 4 3 5 5
*/