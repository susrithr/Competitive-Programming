#include <bits/stdc++.h>
using namespace std;

bool compareMovies(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), compareMovies);

    int total_movies = 0;
    int current_end_time = 0;

    for (int i = 0; i < n; ++i) {
        if (movies[i].first >= current_end_time) {
            total_movies++;
            current_end_time = movies[i].second;
        }
    }

    cout << total_movies << "\n";

    return 0;
}