#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k;
    cin >> k;
    long long length = 1;
    long long count = 9;  
    long long start = 1;
    while (k > length * count) {
        k -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }
    long long target_number = start + (k - 1) / length;
    string s = to_string(target_number);
    int index = (k - 1) % length;  
    cout << s[index] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}