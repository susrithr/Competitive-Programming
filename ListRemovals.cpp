#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

void build(int node, int L, int R) {
    if (L == R) {
        tree[node] = 1;
        return;
    }
    int mid = (L + R) / 2;
    build(2 * node, L, mid);
    build(2 * node + 1, mid + 1, R);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query_and_remove(int node, int L, int R, int p) {
    if (L == R) {
        tree[node] = 0; 
        return L;       
    }
    int mid = (L + R) / 2;
    int res;
    if (tree[2 * node] >= p) {
        res = query_and_remove(2 * node, L, mid, p);
    } else {
        res = query_and_remove(2 * node + 1, mid + 1, R, p - tree[2 * node]);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    tree.assign(4 * n, 0);
    build(1, 1, n);

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        int original_idx = query_and_remove(1, 1, n, p);
        cout << x[original_idx] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}