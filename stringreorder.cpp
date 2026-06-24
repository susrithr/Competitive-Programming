#include<bits/stdc++.h>
using namespace std;

bool is_valid(const vector<int>& freq, int rem_len) {
    int max_freq = 0;
    for (int f : freq) {
        max_freq = max(max_freq, f);
    }
    return max_freq <= (rem_len + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }
    if (!is_valid(freq, n)) {
        cout << "-1\n";
        return 0;
    }

    string result = "";
    char last_char = '#';
    for (int i = 0; i < n; i++) {
        int rem_len = n - i;
        for (int c = 0; c < 26; c++) {
            if (freq[c] > 0 && (char)('A' + c) != last_char) {
                freq[c]--;

                if (is_valid(freq, rem_len - 1)) {
                    last_char = (char)('A' + c);
                    result += last_char;
                    break;
                }
                freq[c]++;
            }
        }
    }

    cout << result << "\n";
    return 0;
}