#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int rounds = 1;
    for (int x = 1; x < n; x++) {
        if (pos[x + 1] < pos[x]) {
            rounds++;
        }
    }
    cout << rounds << "\n";
    return 0;
}