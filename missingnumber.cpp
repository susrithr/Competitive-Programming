#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long expected_sum = n * (n + 1) / 2;
    long long actual_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        long long num;
        cin >> num;
        actual_sum += num;
    }
    cout << expected_sum - actual_sum << "\n";
    return 0;
}