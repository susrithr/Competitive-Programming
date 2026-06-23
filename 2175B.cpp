#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> P(n + 1);
    for (int i = 0; i <= n; ++i) {
        P[i] = i;
    }
    P[r] = P[l - 1];
    for (int i = 1; i <= n; ++i) {
        int val = P[i] ^ P[i - 1];
        cout << val << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}