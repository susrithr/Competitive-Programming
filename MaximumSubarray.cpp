#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int current_sum = x[0];
    int max_sum = x[0];
    for (int i = 1; i < n; ++i) {
        current_sum = max(x[i], current_sum + x[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";

    return 0;
}