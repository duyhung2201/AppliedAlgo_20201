#include <iostream>
using namespace std;

void bai1()
{
    unsigned long long a = 1, b = 2;
    cin >> a >> b;
    if (a > 100 || b > 100)
    {
        unsigned long long a1 = a / 10;
        unsigned long long a2 = a % 10;
        unsigned long long b1 = b / 10;
        unsigned long long b2 = b % 10;

        unsigned long long t = a2 + b2;
        unsigned long long c1 = t / 10;
        unsigned long long c2 = t % 10;

        cout << a1 + b1 + c1 << c2;
    }
    else
    {
        cout << a + b;
    }

    return;
}

void subseqmax()
{
    int len;
    cin >> len;

    int a[len];

    for (int i = 0; i < len; i++)
    {
        cin >> a[i];
    }

    int max = 0, temp = 0;

    for (int i = 0; i < len; i++)
    {
        if (temp > 0)
        {
            temp += a[i];
            max = max > temp ? max : temp;
        }
        else
        {
            temp = a[i];
            max = max > temp ? max : temp;
        }
    }

    cout << max;
    return;
}

void addmod()
{
    unsigned long long a, b;
    cin >> a >> b;

    long long t = 1000000000 + 7;

    // cout << (a + b) % t;

    unsigned long long a1 = a % t, b1 = b % t;

    cout << (a1 + b1) % t;

    return;
}

void expmod()
{
    unsigned long long a, b, res = 1;
    cin >> a >> b;

    unsigned long t = 1000000000 + 7;
    // unsigned long t = 13;
    a = a % t;

    if (b % 2 == 1)
    {
        res = res * a % t;
        b -= 1;
    }

    for (unsigned long long i = b; i > 0; i /= 2)
    {
        if (i % 2 == 1)
        {
            res = res * a % t;
        }
        a = a * a % t;
    }

    cout << res;
}

void sumseq()
{
    unsigned long long n, sum = 0, t = 1000000000 + 7;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        sum += a;
    }

    cout << sum % t;

    return;
}

void tooLongWord()
{
    int n;
    char t[100];
    cin >> n;
    gets(t);

    for (int i = 0; i < n; i++)
    {
        char str[100];
        int countChar = 0;
        gets(str);
        for (int j = 0; str[j] != '\0'; j++)
        {
            countChar++;
        }
        if (countChar > 10)
        {
            cout << str[0] << countChar - 2 << str[countChar - 1] << endl;
        }
        else
        {
            cout << str << endl;
        }
    }

    return;
}

int main()
{
    // bai1();
    // subseqmax();
    // addmod();
    // expmod();
    // sumseq();
    tooLongWord();
}
