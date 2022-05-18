#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
    int t = 1;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        ll n; cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        ll ans = 0;
        
        for(ll i = n - 2; i >= 0; i--){
            while(a[i] && a[i] >= a[i + 1]){
                a[i]/= 2;
                ans++;
            }
        }
        bool ok = 1;
        for(ll i = 1; i < n; i++){
            if(a[i] <= a[i - 1]) ok = 0;
        }
        cout << (ok ? ans : -1) << endl;
    }

	return 0;
}