#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
int const maxn = 2e5 + 5;

int main() {
    int t = 1;
    // cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        int greatest = 0;
        for(int i = 0; i < n; i++) {
             cin >> a[i];
             greatest = max(greatest, a[i]);
        }
        bool ok = 0;
        for(int i = 0; i < k; i++){
            int x; cin >> x; x--;
            ok |= (a[x] == greatest);
        }
        cout << (ok ? "Yes\n" : "No\n");
    } 
    return 0;
}