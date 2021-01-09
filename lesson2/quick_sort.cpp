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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int l, int r)
{
    int k = l;
    for (int i = l; i < r; i++)
    {
        if (a[i] <= a[r - 1])
        {
            swap(a[i], a[k]);
            k++;
        }
    }

    return k - 1;
}

void quickSort(int a[], int l, int r)
{
    if (l + 1 < r)
    {
        int pivot = partition(a, l, r);
        quickSort(a, l, pivot);
        quickSort(a, pivot + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    // int a[] = {1, 6, 4, 3, 9, 5, 2};
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n);
    printArray(a, n);

    return 0;
}