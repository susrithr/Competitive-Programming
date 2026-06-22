#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<long long> p(n);
    long long total_weight = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_weight += p[i];
    }
    long long min_difference = LLONG_MAX;
    int total_subsets = 1 << n;
    for (int mask = 0; mask < total_subsets; ++mask) {
        long long current_group_weight = 0;
        
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                current_group_weight += p[i];
            }
        }
        long long other_group_weight = total_weight - current_group_weight;
        long long current_difference = abs(current_group_weight - other_group_weight);
        min_difference = min(min_difference, current_difference);
    }
    cout << min_difference << "\n";
    return 0;
}