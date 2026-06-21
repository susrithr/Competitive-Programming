#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int i = 0;
    int j = n - 1;
    int gondolas = 0;
    while (i <= j) {
        if (i == j) {
            gondolas++;
            break;
        }
        if (p[i] + p[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        gondolas++;
    }
    cout << gondolas << "\n";
    return 0;
}