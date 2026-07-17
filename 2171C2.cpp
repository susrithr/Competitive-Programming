#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int bit = 20; bit >= 0; --bit) {
        int ajisai_choices = 0;
        int mai_choices = 0;    
        int fixed_xor_sum = 0;

        for (int i = 1; i <= n; ++i) {
            int bit_a = (a[i] >> bit) & 1;
            int bit_b = (b[i] >> bit) & 1;
            if (bit_a != bit_b) {
                if (i % 2 != 0) {
                    ajisai_choices++;
                } else {
                    mai_choices++;
                }
            } else {
                fixed_xor_sum ^= bit_a;
            }
        }

        if (ajisai_choices > mai_choices) {
            cout << "Ajisai\n";
            return;
        } else if (mai_choices > ajisai_choices) {
            cout << "Mai\n";
            return;
        } else {
           
            if (fixed_xor_sum != 0) {
                if (ajisai_choices % 2 != 0) {
                    cout << "Ajisai\n";
                } else {
                    cout << "Mai\n";
                }
                return;
            }
        }
    }
    cout << "Tie\n";
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