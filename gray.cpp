#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int total_codes = 1 << n;
    
    for (int i = 0; i < total_codes; ++i) {
        int gray = i ^ (i >> 1);
        string binary_str = "";
        for (int j = n - 1; j >= 0; --j) {
            if ((gray >> j) & 1) {
                binary_str += '1';
            } else {
                binary_str += '0';
            }
        }
        cout << binary_str << "\n";
    }
    return 0;
}