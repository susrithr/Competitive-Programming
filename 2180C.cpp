#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k % 2 != 0) {
        for (int i = 0; i < k; ++i) {
            cout << n << (i == k - 1 ? "" : " ");
        }
    } else {
        for (int i = 0; i < k - 1; ++i) {
            cout << n << " ";
        }
        cout << 0;
    }
    cout << "\n";
    }
    
    return 0;
}