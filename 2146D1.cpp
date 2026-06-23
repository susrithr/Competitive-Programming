#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
           long long l, r;
    cin >> l >> r; 
    long long n = r - l + 1;
    vector<long long> a(n);
    long long max_or_sum = 0;
    long long curr = r;
    while (curr >= 0) {
        long long mask = 1;
        while (mask < curr) {
            mask = (mask << 1) | 1;
        }
        long long limit = mask - curr;
        for (long long i = limit; i <= curr; ++i) {
            a[i] = mask - i;
            max_or_sum += (i | a[i]);
        }

        curr = limit - 1;
    }
    cout << max_or_sum << "\n";
    for (long long i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    }

    return 0;
}