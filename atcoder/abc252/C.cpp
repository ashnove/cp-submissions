#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
int const maxn = 2e5 + 5;

int main() {
    int t = 1;
    // cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n; cin >> n;
        vector<int> hash(10, 0);
        vector<vector<int>> cnt(10, vector<int>(10, 0));
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            for(int j = 0; j < 10; j++){
                
                hash[s[j] - '0'] = max(hash[s[j] - '0'], j + (cnt[s[j] - '0'][j] * 10));
                cnt[s[j] - '0'][j]++;
            }
        }
        int mostTime = INT_MAX;
        for(int i = 0; i <= 9; i++){
            if(hash[i] < mostTime){
                mostTime = hash[i];
            }
        }
        cout << mostTime << endl;
    } 
    return 0;
}