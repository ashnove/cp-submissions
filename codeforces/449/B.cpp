/*
* @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define Th third
#define nl cout << endl;
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(x) cerr << #x << " is " << x << endl;

using lld = long double;
using ll = long long int;
using ar = vector<ll>;
using mat = vector<vector<ll>>;
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}

ll const MOD = 1000000007;
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0;}
template<class T> inline void add(T &a, T b) { a += b; a >= MOD ? a - MOD : a; }
template<class T> inline void sub(T &a, T b) { a -= b; a < 0 ? a + MOD : a; }
template<class T> inline void mul(T &a, T b) {return (a * b) % MOD; }
template<class T> void remDup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), end(v)); }

bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
            return 1;
      return 0;
}
class Pair { public: ll first, second;};
bool comp3(const Pair &a, const Pair &b) {
      if (a.F > b.F) return 1; return 0;
}
class Trips { public: ll first, second, third;};
bool comp4(const Trips &a, const Trips &b) {
      if (a.Th > b.Th) return 1; return 0;
}

void readArray(ll a[], int n) {
      for (ll i = 0; i < n ; i++)
            cin >> a[i];
}

ll const inf = 1e18;
// ll const mod = 1e9 + 7;
ll const maxn = 1e5 + 1;


void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            ll n, m, k; cin >> n >> m >> k;

            vector<pair<ll, ll>> adj[n + 1];
            for (ll i = 0; i < m; i++) {
                  ll u, v; cin >> u >> v;
                  ll w; cin >> w;
                  adj[u].pb({v, w});
                  adj[v].pb({u, w});
            }
            ll newRoad[n + 1];
            ll res = 0;
            fill(newRoad, newRoad + n + 1, -1);
            for (ll i = 0; i < k; i++) {
                  ll x, y; cin >> x >> y;
                  if (newRoad[x] != -1)
                        res++, chmin(newRoad[x], y);
                  else newRoad[x] = y;
            }

            priority_queue<pair<ll, ll>> q;
            q.push({0, 1});
            vector<ll> dis(n + 1, inf);
            dis[1] = 0;
            for (ll i = 1; i <= n; i++) {
                  if (newRoad[i] != -1) {
                        q.push({ -newRoad[i], i});
                        dis[i] = newRoad[i];
                  }
            }

            while (!q.empty()) {
                  ll from = q.top().S;
                  ll w = -q.top().F;
                  q.pop();
                  if (w > dis[from]) continue;
                  for (auto e : adj[from]) {
                        ll to = e.F, ww = e.S;
                        if (dis[from] + ww < dis[to]) {
                              dis[to] = ww + dis[from];
                              q.push({ -dis[to], to});
                        }
                  }
            }

            for (ll i = 1; i <= n; i++) {
                  if (newRoad[i] != -1) {
                        for (auto e : adj[i]) {
                              ll from = e.F, ww = e.S;
                              if (dis[i] == ww + dis[from]) {
                                    res++;
                                    break;
                              }
                        }
                  }
            }

            cout << res << endl;

      }
}





int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      /*
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif/**/

      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}