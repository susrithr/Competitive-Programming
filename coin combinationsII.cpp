#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x)) return 0;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    const int MOD = 1e9 + 7;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int weight = coins[i]; weight <= x; weight++) {
            dp[weight] = (dp[weight] + dp[weight - coins[i]]) % MOD;
        }
    }
    cout << dp[x] << "\n";

    return 0;
}