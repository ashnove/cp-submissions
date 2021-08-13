#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;
int const inf = 1e9 + 1;

int main() {

      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      int n,m; cin >> n >> m;

      ll ans = 0;
      vector<int> adj[n + 1];
      for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
      }
      unordered_map<int, int> cnt;
      for(int i = 1; i <= n; i++){

            for(int i_ch : adj[i]){
                  for(int i_ch_ch: adj[i_ch])
                        cnt[i_ch_ch]++;
            }
            for(auto e : cnt){
                  if(e.first != i)
                  ans += (e.second * (e.second - 1))/2;
            }
            cnt.clear();
      }
      cout << ans;
      return 0;
}