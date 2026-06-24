#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if (!(cin >> s)) return 0;
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }
    int odd_count = 0;
    int odd_index = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd_count++;
            odd_index = i;
        }
    }
    if (odd_count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    string left_half = "";
    string middle = "";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            left_half.append(freq[i] / 2, (char)('A' + i));
        }
    }
    if (odd_index != -1) {
        middle.append(freq[odd_index], (char)('A' + odd_index));
    } else {
        middle = "";
    }
    string right_half = left_half;
    reverse(right_half.begin(), right_half.end());
    left_half = "";
    for (int i = 0; i < 26; i++) {
        left_half.append(freq[i] / 2, (char)('A' + i));
    }
    right_half = left_half;
    reverse(right_half.begin(), right_half.end());
    middle = "";
    if (odd_index != -1) {
        middle.append(freq[odd_index], (char)('A' + odd_index));
    }
    cout << left_half << middle << right_half << "\n";

    return 0;
}