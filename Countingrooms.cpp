#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y) {
    grid[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int room_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                room_count++;
                dfs(i, j);
            }
        }
    }
    cout << room_count << "\n";
    return 0;
}