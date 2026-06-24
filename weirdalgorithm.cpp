#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin>>n;
    vector<int>vec(n-1);
    for(int i=0;i<(n-1);i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int j=1;
    for(int k=0;k<(n-1);k++){
        if(j%vec[k]==0){++j;continue;}
        else{cout<<vec[k];break;}
    }
    return 0;
}