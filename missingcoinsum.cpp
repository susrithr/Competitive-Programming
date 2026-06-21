#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    long long current_tracked_sum = 1;

    for (int i = 0; i < n; ++i) {
        if (x[i] > current_tracked_sum) {
            break;
        }
        current_tracked_sum += x[i];
    }
    cout << current_tracked_sum << "\n";
    return 0;
}