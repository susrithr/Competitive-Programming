#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

class SegmentTree {
private:
    int n;
    vector<long long> tree;
    void build(const vector<long long>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INF;
        }
        if (l <= start && end <= r) {
            return tree[node]; 
        }
        int mid = (start + end) / 2;
        long long left_min = query(2 * node, start, mid, l, r);
        long long right_min = query(2 * node + 1, mid + 1, end, l, r);
        return min(left_min, right_min);
    }

public:
    SegmentTree(const vector<long long>& a) {
        n = a.size();
        tree.assign(4 * n, INF);
        build(a, 1, 0, n - 1);
    }
    void update(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegmentTree st(a);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            st.update(k - 1, u);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r - 1) << "\n";
        }
    }
    return 0;
}