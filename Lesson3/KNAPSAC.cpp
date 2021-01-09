#include <iostream>
using namespace std;

int n, b, a[30], c[30], best = 0;
void printArray(int a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solution(int p, int A, int C)
{
    if (p > n)
    {
        if (A <= b)
            best = max(best, C);
        return;
    }

    solution(p + 1, A, C);
    if (A + a[p] <= b) // nhanh can ve rang buoc cua nghiem, ko phai nhanh can ham muc tieu
    {
        solution(p + 1, A + a[p], C + c[p]);
    }
}

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
    }
    solution(0, 0, 0);
    cout << best;
}