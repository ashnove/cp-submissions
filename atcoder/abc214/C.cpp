#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;
ll const inf = 1e18;
int const maxn = 1e5 + 1;
vector<ll> adj[maxn];

int main() {

      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      ll n; cin >> n;
      vector<ll> s(n + n), t(n + n);
      for(ll i = 0; i < n; i++) {cin >> s[i]; s[i + n] = s[i];}
      for(ll i = 0; i < n; i++) {cin >> t[i]; t[i + n] = t[i];}
      vector<ll> ans = t;
      for(ll i = 0; i < 2 * n; i++) {

            ans[(i+1)%n] = min(ans[(i+1)%n], ans[i%n] + s[i%n]);

      }
      for(ll i = 0; i < n; i++) cout << ans[i] << endl;

      return 0;
}