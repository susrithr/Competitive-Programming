#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    int Q;
    if (!(cin >> N >> Q)) return 0;
    set<pair<long long, long long>> inter;
    long long total_black = 0;
    for (int i = 0; i < Q; ++i) {
        long long L, R;
        cin >> L >> R;
        long long cur_L = L;
        long long cur_R = R;
        auto it = inter.lower_bound({L, 0});
        if (it != inter.begin()) {
            auto prev_it = prev(it);
            if (prev_it->second >= cur_L - 1) {
                cur_L = min(cur_L, prev_it->first);
                cur_R = max(cur_R, prev_it->second);
                total_black -= (prev_it->second - prev_it->first + 1);
                inter.erase(prev_it);
            }
        }
        while (it != inter.end() && it->first <= cur_R + 1) {
            cur_R = max(cur_R, it->second);
            total_black -= (it->second - it->first + 1);
            it = inter.erase(it);
        }
        total_black += (cur_R - cur_L + 1);
        inter.insert({cur_L, cur_R});
        cout << N - total_black << "\n";
    }
    return 0;
}
