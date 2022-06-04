#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int N, int K)
{
    int dp[K + 1][N];

    for (int i = 0; i < N; i++)
        dp[0][i] = 1;

    for (int i = 1; i < K + 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;

            int y = (j >= 1) ? dp[i][j - 1] : 0;

            // Total.
            dp[i][j] = x + y;
        }
    }
    return dp[K][N - 1];
}

int main()
{
    int N, K;
    cin >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    cin >> K;

    cout << coinChange(coins, N, K);
    return 0;
}