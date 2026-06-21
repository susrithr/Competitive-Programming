#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> events;
    events.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        int arrival, leaving;
        cin >> arrival >> leaving;
        events.push_back({arrival, 1}); 
        events.push_back({leaving, -1});
    }
    sort(events.begin(), events.end());
    int current_customers = 0;
    int max_customers = 0;
    for (const auto& event : events) {
        current_customers += event.second;
        if (current_customers > max_customers) {
            max_customers = current_customers;
        }
    }
    cout << max_customers << "\n";
    return 0;
}