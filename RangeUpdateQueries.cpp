#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    int n;
    vector<long long> tree;

public:
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n + 2, 0);
    }

    void add(int i, long long val) {
        for (; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> a(n + 1);
    FenwickTree ft(n);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ft.add(i, a[i] - a[i - 1]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a_idx, b_idx;
            long long u;
            cin >> a_idx >> b_idx >> u;
            ft.add(a_idx, u);
            ft.add(b_idx + 1, -u);
        } else if (type == 2) {
            int k;
            cin >> k;
            cout << ft.query(k) << "\n";
        }
    }
    return 0;
}