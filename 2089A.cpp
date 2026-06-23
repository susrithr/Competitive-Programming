#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
         int n;
    cin >> n;
    if (n <= 3) {
        for (int i = 1; i <= n; ++i) {
            cout << i << (i == n ? "" : " ");
        }
        cout << "\n";
        return;
    }
    int P = n / 2;
    while (!is_prime(P)) {
        P--;
    }

    vector<int> ans;
    vector<bool> used(n + 1, false);
    ans.push_back(P);
    used[P] = true;
    int k = 1;
    while (true) {
        bool added = false;
        if (P - k >= 1 && P + k <= n) {
            ans.push_back(P - k);
            ans.push_back(P + k);
            used[P - k] = true;
            used[P + k] = true;
            k++;
            added = true;
        }
        if (!added) break;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    }

    return 0;
}