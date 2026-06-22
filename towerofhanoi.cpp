#include<bits/stdc++.h>
using namespace std;

void Hanoi(int n, int from_rod, int to_rod, int aux_rod, vector<pair<int, int>>& moves) {
    if (n == 1) {
        moves.push_back({from_rod, to_rod});
        return;
    }
    Hanoi(n - 1, from_rod, aux_rod, to_rod, moves);
    moves.push_back({from_rod, to_rod});
    Hanoi(n - 1, aux_rod, to_rod, from_rod, moves);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> moves;
    Hanoi(n, 1, 3, 2, moves);
    cout << moves.size() << "\n";
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << "\n";
    }
    return 0;
}