#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int tree[4 * MAXN];
int h[MAXN];
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = h[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query_and_update(int node, int start, int end, int val) {
    if (tree[node] < val) {
        return 0;
    }
    if (start == end) {
        tree[node] -= val;
        return start; 
    }
    
    int mid = (start + end) / 2;
    int res = 0;
    if (tree[2 * node] >= val) {
        res = query_and_update(2 * node, start, mid, val);
    } else {
        res = query_and_update(2 * node + 1, mid + 1, end, val);
    }

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;
        cout << query_and_update(1, 1, n, r) << (i == m - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}