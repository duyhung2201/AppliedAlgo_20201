//
//  main.cpp
//  PLCNT
//
//  Created by Duy Hung Le on 18/12/2020.
//

#include <iostream>
#include <string>
using namespace std;
string s;

int dp[5001][5001]; //
bool isPal(int i, int j)
{
    if (i > j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] != s[j])
        return dp[i][j] = 0;

    dp[i][j] = isPal(i + 1, j - 1);
    return dp[i][j];
}

int countSubstrings()
{
    int n = (int)s.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPal(i, j))
                count++;
        }
    }
    return count;
}

int main()
{
    cin >> s;
    for (int i = 0; i <= s.size() + 1; i++)
    {
        for (int j = 0; j <= s.size() + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << s.size() + countSubstrings();

    return 0;
}

// acacbbcbab
