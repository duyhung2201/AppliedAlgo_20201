#include <iostream>
#include <stack>
using namespace std;
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

unsigned long long maxS = 0;
int a[1000000 + 1]; // mang lon qua de tran stack
int left1[1000000 + 1];
int right1[1000000 + 1];

int main()
{
    while (true)
    {
        maxS = 0;
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }

        a[0] = 0;
        a[n + 1] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            cin >> a[i];
        }
        stack<int> st;
        st.push(0);

        for (int i = 1; i < n + 1; i++)
        {
            while (a[i] > 0 && a[i] <= a[st.top()])
            {
                st.pop();
            }
            left1[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();
        st.push(n + 1);
        for (int i = 1; i < n + 1; i++)
        {
            while (a[n + 1 - i] > 0 && a[n + 1 - i] <= a[st.top()])
            {
                st.pop();
            }
            right1[n + 1 - i] = st.top();
            st.push(n + 1 - i);
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (a[i] == 0)
            {
                continue;
            }
            unsigned long long s = 1ll * a[i] * (right1[i] - left1[i] - 1);
            maxS = s > maxS ? s : maxS;
        }

        cout << maxS << endl;
    }

    return 0;
}