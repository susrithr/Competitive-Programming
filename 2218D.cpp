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
    cout << 1;
    for (long long i = 2; i <= n; ++i) {
        cout << " " << i * (i - 1);
    }
    cout << "\n";
    }
    
    return 0;
}