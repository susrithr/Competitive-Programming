#include<bits/stdc++.h>
using namespace std;

const int MAX_VAL = 500005;
struct Fenwick {
    int n;
    vector<long long> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, long long delta) {
        i++;
        while (i <= n) {
            tree[i] += delta;
            i += i & -i;
        }
    }
    long long query(int i) {
        i++; 
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }
    long long query_range(int l, int r) {
        if (l > r) {return 0;}
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> a(n + 1);
    Fenwick cnt_bit(MAX_VAL);
    Fenwick sum_bit(MAX_VAL);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt_bit.add(a[i], 1);
        sum_bit.add(a[i], a[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            cnt_bit.add(a[x], -1);
            sum_bit.add(a[x], -a[x]);
            a[x] = y;
            cnt_bit.add(a[x], 1);
            sum_bit.add(a[x], a[x]);
        } else {
            int l, r;
            cin >> l >> r;
            if (l > r) {
                cout << (long long)n * l << "\n";
            } else {
                long long count_le_l = cnt_bit.query_range(0, l);
                long long ans = count_le_l * l;
                ans += sum_bit.query_range(l + 1, r - 1);

                // Elements >= r contribute `r`
                long long count_ge_r = cnt_bit.query_range(r, MAX_VAL - 1);
                ans += count_ge_r * r;

                cout << ans << "\n";
            }
        }
    }
    return 0;
}