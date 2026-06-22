#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;
    map<long long, int> val_to_index;
    for (int i = 1; i <= n; i++) {
        long long current_val;
        cin >> current_val;
        long long complement = x - current_val;
        if (val_to_index.count(complement)) {
            cout << val_to_index[complement] << " " << i << "\n";
            return 0;
        }
        val_to_index[current_val] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}