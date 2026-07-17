#include <bits/stdc++.h>
using namespace std;

const int MAXA = 2000005; 
long long cnt[MAXA];
long long sum[MAXA];

void solve() {
    int n;
    long long x, y;
    if (!(cin >> n >> x >> y)) return;
    long long max_val = 0;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        cnt[a]++;
        sum[a] += a;
        max_val = max(max_val, a);
    }
    for (int i = 1; i < MAXA; ++i) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }
    long long min_total_cost = -1;
    for (int g = 2; g <= max_val + 1; ++g) {
        long long current_gcd_cost = 0;
        long long max_increment = x / y;
        for (int r = g; r < MAXA; r += g) {
            int l = r - g;
            int mid = max((long long)l, r - max_increment - 1);
            long long delete_count = cnt[mid] - cnt[l];
            current_gcd_cost += delete_count * x;

            long long inc_count = cnt[r] - cnt[mid];
            long long inc_sum = sum[r] - sum[mid];
            current_gcd_cost += (inc_count * r - inc_sum) * y;
        }

        if (min_total_cost == -1 || current_gcd_cost < min_total_cost) {
            min_total_cost = current_gcd_cost;
        }
    }

    cout << min_total_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}