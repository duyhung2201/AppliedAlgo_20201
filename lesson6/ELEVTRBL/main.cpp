// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <initializer_list>
using namespace std;

int f[1000001];
int fCnt, s, g, u, d;

int main()
{
    cin >> fCnt >> s >> g >> u >> d;
    int step[2] = {u, -d};
    for (int i = 1; i <= fCnt; i++)
        f[i] = -1;
    f[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int y : {x + u, x - d})
        // for (int i = 0; i < 2; i++)
        {
            // int y = x + step[i];
            if (y >= 1 && y <= fCnt && f[y] == -1)
            {
                q.push(y);
                f[y] = f[x] + 1;
                if (y == g)
                {
                    q = queue<int>();
                    break;
                }
            }
        }
    }

    if (f[g] == -1)
        cout << "use the stairs";
    else
        cout << f[g];
}