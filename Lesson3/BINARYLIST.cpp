#include <iostream>
using namespace std;
void printArray(int a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int a[10000], n, m, k, c, isSolve;

void solution(int p)
{
    for (int i = a[p - 1] + 1; i <= n; i++)
    {
        a[p] = i;
        if (p == m)
        {
            c++;
            if (c == k)
            {
                printArray(a, m + 1);
                isSolve = true;
                return;
            }
        }
        solution(p + 1);
    }
}

int main()
{
    a[0] = 0;
    c = 0;
    isSolve = false;
    cin >> n >> m >> k;
    if (m < n)
    {
        cout << -1;
        return 0;
    }
    solution(1);
    if (!isSolve)
    {
        cout << -1;
    }
    return 0;
}