#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> prime_factor_count(MAXN, 0);
vector<pair<int, int>> semi_prime_factors(MAXN, {0, 0});
void precompute() {
    vector<int> spf(MAXN);
    for (int i = 2; i < MAXN; ++i) spf[i] = i;
    for (int i = 2; i * i < MAXN; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    for (int i = 2; i < MAXN; ++i) {
        int temp = i;
        int count = 0;
        int p1 = 0, p2 = 0;
        while (temp > 1) {
            int p = spf[temp];
            count++;
            if (count == 1) p1 = p;
            else if (count == 2) p2 = p;
            temp /= p;
        }
        prime_factor_count[i] = count;
        if (count == 2) {
            semi_prime_factors[i] = {p1, p2};
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<long long> cnt(n + 1, 0);
    long long total_primes = 0;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt[val]++;
        if (prime_factor_count[val] == 1) {
            total_primes++;
        }
    }

    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (prime_factor_count[i] == 1 && cnt[i] > 0) {
            ans += cnt[i] * (total_primes - cnt[i]);
        }
    }
    ans /= 2; 
    for (int i = 2; i <= n; ++i) {
        if (prime_factor_count[i] == 2 && cnt[i] > 0) {
            ans += cnt[i] * (cnt[i] + 1) / 2;
            int p1 = semi_prime_factors[i].first;
            int p2 = semi_prime_factors[i].second;

            if (p1 == p2) {
                ans += cnt[i] * cnt[p1];
            } else {
                ans += cnt[i] * cnt[p1];
                ans += cnt[i] * cnt[p2];
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}