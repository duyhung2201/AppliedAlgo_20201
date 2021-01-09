#include <iostream>
#include <string>
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

bool checkpair(char open, char close)
{
    if ((open == '[' && close == ']') ||
        (open == '{' && close == '}') ||
        (open == '(' && close == ')'))
    {
        return true;
    }
    return false;
}

int parentheses()
{
    string str;
    cin >> str;

    int i = 0;
    while (true)
    {
        if (str.length() == 0)
        {
            return 1;
        }
        if (str[i] == '\0')
        {
            return 0;
        }

        if (checkpair(str[i], str[i + 1]))
        {
            str.erase(i, 2);
            i = 0;
            continue;
        }
        i++;
    }

    return 0;
}

int altParentheses()
{
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return 0;
            if ((st.top() == '(' && c != ')') ||
                (st.top() == '[' && c != ']') ||
                (st.top() == '{' && c != '}'))
                return 0;

            st.pop();
        }
    }
    return st.empty();
}

void baiH()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // int t = parentheses();
        int t = altParentheses();
        cout << t << endl;
    }

    return;
}

void baiK()
{
    int n;
    cin >> n;
    int a[n + 1], res[n];
    a[n] = (1 << 31) - 1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] <= a[j])
            {
                res[i] = j - i - 2;
                break;
            }
        }
    }

    printArray(res, n);
}

int main()
{
    // int a[5] = {2, 5, 6, 4, 8};
    // mergeSort(a, 0, 4);
    // baiH();
    baiK();

    return 0;
}