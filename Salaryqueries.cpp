#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
    int size;
    vector<int> tree;
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}
    void update(int i, int delta) {
        for (; i <= size; i += i & -i) {
            tree[i] += delta;
        }
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

struct Query {
    char type;
    int arg1;
    int arg2;
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> initial_salaries(n + 1);
    vector<Query> queries(q);
    vector<int> values; 
    values.reserve(n + 2 * q);

    for (int i = 1; i <= n; ++i) {
        cin >> initial_salaries[i];
        values.push_back(initial_salaries[i]);
    }
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type >> queries[i].arg1 >> queries[i].arg2;
        if (queries[i].type == '!') {
            values.push_back(queries[i].arg2);
        } else {
            values.push_back(queries[i].arg1);
            values.push_back(queries[i].arg2);
        }
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    auto get_compressed_idx = [&](int val) {
        return lower_bound(values.begin(), values.end(), val) - values.begin() + 1;
    };

    int compressed_size = values.size();
    FenwickTree bit(compressed_size);
    vector<int> current_salaries = initial_salaries;
    for (int i = 1; i <= n; ++i) {
        bit.update(get_compressed_idx(current_salaries[i]), 1);
    }
    for (int i = 0; i < q; ++i) {
        if (queries[i].type == '!') {
            int employee = queries[i].arg1;
            int new_salary = queries[i].arg2;

            int old_salary_idx = get_compressed_idx(current_salaries[employee]);
            bit.update(old_salary_idx, -1);
            current_salaries[employee] = new_salary;
            int new_salary_idx = get_compressed_idx(new_salary);
            bit.update(new_salary_idx, 1);
        } else {
            int a = queries[i].arg1;
            int b = queries[i].arg2;
            int l_idx = lower_bound(values.begin(), values.end(), a) - values.begin() + 1;
            int r_idx = upper_bound(values.begin(), values.end(), b) - values.begin();
            cout << bit.query(l_idx, r_idx) << "\n";
        }
    }

    return 0;
}