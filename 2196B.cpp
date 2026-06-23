#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int B = max(1, (int)sqrt(n));
    long long beautiful_pairs = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= B) {
            for (int j = i + a[i]; j <= n; j += a[i]) {
                if (a[i] * a[j] == j - i) {
                    beautiful_pairs++;
                }
            }
        } else {
            for (int v = 1; v < B; ++v) {
                long long j = i + (long long)v * a[i];
                if (j <= n && a[j] == v) {
                    beautiful_pairs++;
                }
            }
        }
        if (a[i] >= B) {
            for (int prev = i - a[i]; prev >= 1; prev -= a[i]) {
                if (a[prev] < B && a[prev] * a[i] == i - prev) {
                    beautiful_pairs++;
                }
            }
        }
    }
    cout << beautiful_pairs << "\n";
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