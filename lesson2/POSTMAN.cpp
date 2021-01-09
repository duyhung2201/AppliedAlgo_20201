#include <iostream>
using namespace std;
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int a[], int w[], int l, int m, int r)
{
    int i = 0, j = m - l, temp1[r - l], temp2[r - l];
    for (int k = l; k < r; k++)
    {
        temp1[k - l] = a[k];
        temp2[k - l] = w[k];
    }

    for (int k = l; k < r; k++)
    {
        if (l + i >= m)
        {
            a[k] = temp1[j];
            w[k] = temp2[j];
            j++;
        }
        else if (l + j >= r)
        {
            a[k] = temp1[i];
            w[k] = temp2[i];
            i++;
        }
        else
        {
            if (temp1[i] < temp1[j])
            {
                a[k] = temp1[i];
                w[k] = temp2[i];
                i++;
            }
            else
            {
                a[k] = temp1[j];
                w[k] = temp2[j];
                j++;
            }
        }
    }
}

void mergeSort(int a[], int w[], int l, int r)
{
    if (l + 1 < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, w, l, m);
        mergeSort(a, w, m, r);
        merge(a, w, l, m, r);
    }

    return;
}

int main()
{

    int n, k;
    cin >> n >> k;
    int x[n], m[n];
    unsigned long long time = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> m[i];
    }

    mergeSort(x, m, 0, n);

    int i = 0;

    while (x[i] < 0 && i < n)
    {
        if (m[i] == 0)
        {
            i++;
            continue;
        }
        int w = k;
        if (m[i] > k)
        {
            int num = m[i] / w;
            time -= 1ll * 2 * num * x[i];
            m[i] = m[i] % k;
            // cout << x[i] << " mi: " << m[i] << " time: " << time << endl;
            continue;
        }
        else if (m[i] < k)
        {
            time -= 1ll * 2 * x[i];
            w -= m[i];
            i++;
        }

        while (x[i] < 0 && i < n)
        {
            if (m[i] <= w)
            {
                w -= m[i];
                m[i] = 0;
                i++;
            }
            else
            {
                m[i] -= w;
                break;
            }
        }
        // cout << x[i] << "mi: " << m[i] << " time: " << time << endl;
    }

    i = n - 1;
    while (x[i] > 0 && i >= 0)
    {
        if (m[i] == 0)
        {
            i--;
            continue;
        }
        int w = k;
        if (m[i] > k)
        {
            int num = m[i] / w;
            time += 1ll * 2 * num * x[i];
            m[i] = m[i] % k;
            // cout << x[i] << "mi: " << m[i] << " time: " << time << endl;
            continue;
        }
        else
        {
            time += 1ll * 2 * x[i];
            w -= m[i];
            i--;
        }

        while (x[i] > 0 && i >= 0)
        {
            if (m[i] <= w)
            {
                w -= m[i];
                m[i] = 0;
                i--;
            }
            else
            {
                m[i] -= w;
                break;
            }
        }
        // cout << x[i] << "mi: " << m[i] << " time: " << time << endl;
    }

    cout << time;
    return 0;
}

// 7 1
// 94 10
// 95 10
// 96 10
// 97 10
// 98 10
// 99 10
// 100 10
