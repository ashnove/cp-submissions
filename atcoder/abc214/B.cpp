#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;
int const inf = 1e9 + 1;
int const maxn = 1e5 + 1;
vector<ll> adj[maxn];

int main() {

      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      ll s,t; cin >> s >> t;
      ll ans = 0;
      for(ll i = 0; i <= 100; i++){
            for(ll j = 0; j <= 100; j++){
                  for(ll k = 0; k <= 100; k++){
                        if(i + j + k <= s && i * j * k <= t) ans++;
                  }
            }
      }
      cout << ans;
      return 0;
}