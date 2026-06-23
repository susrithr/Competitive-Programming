#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
          int n;
    cin >> n;
    vector<long long> p(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> s[i];
    if (p[n] != s[1]) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (p[i] % p[i + 1] != 0) {
            cout << "NO\n";
            return;
        }
        if (s[i + 1] % s[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i < n; ++i) {
        long long g = gcd(p[i], s[i + 1]);
        
        if (g % p[i + 1] != 0 || g % s[i] != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    }

    return 0;
}