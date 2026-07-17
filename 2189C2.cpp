#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0) {
        cout << -1 << "\n";
        return;
    }
    vector<int> p(n + 1);
    if (n % 2 != 0) {
        p[1] = n - 1;
        for (int i = 2; i <= n - 1; i += 2) {
            p[i] = i + 1;
            p[i + 1] = i;
        }
        p[n] = 1;
    }
    else {
        int x = n & -n;
        p[1] = x + 1;
        for (int i = 2; i < x; i += 2) {
            p[i] = i + 1;
            p[i + 1] = i;
        }
        p[x] = n;
        p[x + 1] = x;
        for (int i = x + 2; i < n; i += 2) {
            p[i] = i + 1;
            p[i + 1] = i;
        }
        p[n] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    }

    return 0;
}