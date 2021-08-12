#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;

int main() {

ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


      ll n; cin >> n;
      vector<ll> a(n);
      unordered_map<ll,ll> count;
      for (ll i = 0; i < n; i++){
            cin >> a[i];
            ++count[a[i]];
      }

      ll cost = 0;
      for (ll i = 1; i <= 2*n - 2; i++) {

            if(count[i] > 1){
                  ll shift = count[i] - 1;
                  count[i + 1] += shift;
                  cost += shift;
            }

      }
      cout << cost;

      return 0;
}