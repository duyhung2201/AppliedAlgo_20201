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

void merge(int a[], int l, int m, int r)
{
    int i = 0, j = m - l, temp[r - l];
    for (int k = l; k < r; k++)
    {
        temp[k - l] = a[k];
    }

    for (int k = l; k < r; k++)
    {
        if (l + i >= m)
        {
            a[k] = temp[j];
            j++;
        }
        else if (l + j >= r)
        {
            a[k] = temp[i];
            i++;
        }
        else
        {
            if (temp[i] < temp[j])
            {
                a[k] = temp[i];
                i++;
            }
            else
            {
                a[k] = temp[j];
                j++;
            }
        }
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l + 1 < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m, r);
        merge(a, l, m, r);
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n);
    printArray(a, n);

    return 0;
}