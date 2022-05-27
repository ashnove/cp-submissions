#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
int const maxn = 2e5 + 5;

int main() {
    int t = 1;
    // cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n; cin >> n;
        vector<lint> hash(maxn, 0);
        vector<lint> a(n, 0);
        lint max_element = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            hash[a[i]]++;
            max_element = max(a[i], max_element);
        }
        for(int i = 1; i <= max_element; i++){
            hash[i] += hash[i - 1];
        }
        lint ans = 0;
        for(int i = 0; i < n; i++){
            ans += (hash[a[i] - 1] * (hash[max_element]-hash[a[i]]));
        }
        cout << ans << endl;
    } 
    return 0;
}