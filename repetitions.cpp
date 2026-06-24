#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        int max_rep = 1;
        int current_rep = 1;

        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                current_rep++;
            } else {
                max_rep = max(max_rep, current_rep);
                current_rep = 1; 
            }
        }
        max_rep = max(max_rep, current_rep);

        cout << max_rep << "\n";
    }

    return 0;
}