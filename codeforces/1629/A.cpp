#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n,k; cin >> n >> k;
        vector<pair<int,int>> ram(n);
        for(int i = 0; i < n; i++){
            cin >> ram[i].first;
        }
        for(int i = 0; i < n; i++){
            cin >> ram[i].second;
        }
        sort(ram.begin(), ram.end());
        for(pair<int,int> i : ram){
            if(i.first <= k){
                k+=i.second;
            }
            else {
                break;
            }
        }
        cout << k << endl;
    } 
    return 0;
}