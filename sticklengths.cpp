#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int median = p[n / 2];
    int cost_billions = 0;
    int cost_rem = 0;
    for (int i = 0; i < n; ++i) {
        int diff = abs(p[i] - median);
        cost_rem += diff;
        if (cost_rem >= 1000000000) {
            cost_billions += cost_rem / 1000000000;
            cost_rem %= 1000000000;
        }
    }
if (cost_billions > 0) {
        cout << cost_billions;
        cout << setfill('0') << setw(9) << cost_rem << "\n";
    } else {
        cout << cost_rem << "\n";
    }
    return 0;
}