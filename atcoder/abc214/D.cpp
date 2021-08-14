#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;
ll const inf = 1e18;
int const maxn = 1e5 + 1;

vector<ll> parent(maxn, -1), Rank(maxn, 1);
ll find(ll x){
      if(parent[x] < 0)
            return x;
      return parent[x] = find(parent[x]);
}

void merge(ll a, ll b){
      if(Rank[a] > Rank[b]){
            Rank[a] += Rank[b];
            parent[b] = a;
      }
      else{
            Rank[b] += Rank[a];
            parent[a] = b;
      }
}

int main() {

      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      
      ll n; cin >> n;
      vector<pair<ll, pair<ll,ll>>> edg;
      for(ll i = 0; i < n - 1; i++) {
            ll u,v,w; cin >> u >> v >> w;
            edg.push_back({w, {u, v}});
      }
      sort(edg.begin(), edg.end());
      ll ans = 0;
      for(ll i = 0; i < n - 1; i++){
            ll a = edg[i].second.first, b = edg[i].second.second;
            a = find(a), b = find(b);
            if(a!=b){
                  ans += edg[i].first * (Rank[a] * Rank[b]);
                  merge(a, b);

            }
            else{
                  ans += edg[i].first * (Rank[a] * (Rank[a]-1) / 2);
            }
      }
      cout << ans;
      return 0;
}