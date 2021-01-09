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

// void initArray(int a[r][c], int r, int c)
// {
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             a[i][j] = 0;
//         }
//     }
// }

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int L, C;
        cin >> L >> C;
        int r1[L * C], c1[L * C], r2[L * C], c2[L * C], count1 = 0, count2 = 0, res[2 * L][2 * C];
        // initArray(res, L, C);

        for (int l = 0; l < 2 * L; l++)
        {
            for (int c = 0; c < 2 * C; c++)
            {
                res[l][c] = 0;
            }
        }

        for (int l = 0; l < L; l++)
        {
            for (int c = 0; c < C; c++)
            {
                int a;
                cin >> a;
                if (a == 1)
                {
                    r1[count1] = l;
                    c1[count1] = c;
                    count1++;
                }
            }
        }
        for (int l = 0; l < L; l++)
        {
            for (int c = 0; c < C; c++)
            {
                int a;
                cin >> a;
                if (a == 1)
                {
                    r2[count2] = l;
                    c2[count2] = c;
                    count2++;
                }
            }
        }

        for (int j = 0; j < count1; j++)
        {
            for (int k = 0; k < count2; k++)
            {
                res[r2[k] + L - r1[j]][c2[k] + C - c1[j]]++;
            }
        }

        int max = 0;
        for (int j = 0; j < 2 * L; j++)
        {
            for (int k = 0; k < 2 * C; k++)
            {
                max = max > res[j][k] ? max : res[j][k];
            }
        }
        cout << max << endl;

        // for (int l = 0; l < L; l++)
        // {
        //     for (int c = 0; c < C; c++)
        //     {
        //         cout << res[l][c] << " ";
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}