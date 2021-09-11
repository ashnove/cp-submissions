/*
* @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(dp2) (dp2).begin(),(dp2).end()
#define F first
#define S second
#define Th third
#define nl cout << endl;
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(dp2) cerr << #dp2 << " is " << dp2 << endl;

using lld = long double;
using ll = long long int;
using ar = vector<ll>;
using mat = vector<vector<ll>>;
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}

ll const MOD = 1000000007;
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmadp2(T &a, T b) { return a < b ? a = b, 1 : 0;}
template<class T> inline void add(T &a, T b) { a += b; a >= MOD ? a - MOD : a; }
template<class T> inline void sub(T &a, T b) { a -= b; a < 0 ? a + MOD : a; }
template<class T> inline void mul(T &a, T b) {return (a * b) % MOD; }
template<typename T> ostream& operator <<(ostream &out, const vector<T> &v) { for (auto &dp2 : v) out << dp2 << ' '; return out;}
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

ll const inf = 1e9 + 7;
ll const maxn = 5e5 + 1;
vector<ll> parent(maxn, -1), Rank(maxn, 1);

ll find(ll x) {
      if (parent[x] < 0)
            return x;
      return parent[x] = find(parent[x]);
}

void merge(ll a, ll b) {
      a = find(a), b = find(b);
      if (a == b) return;
      if (Rank[a] > Rank[b]) {
            Rank[a] += Rank[b];
            parent[b] = a;
      }
      else {
            Rank[b] += Rank[a];
            parent[a] = b;
      }
}

void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            // cout << "Case " <<tt<<": ";
            ll n; cin >> n;
            ll m; cin >> m;
            ll ans = 0;
            vector< pair<ll, pair<ll, ll>> > vv;
            // vector< pair<ll, pair<ll,ll>> > vvNeg;
            for (ll i = 0; i < m; i++) {
                  ll u, v, w; cin >> u >> v >> w;
                  vv.pb({w, {u , v}});
                  // ans += w;
            }
            sort(all(vv));
            ans = 0;
            map< pair<ll, ll>, ll> merged;
            for (ll i = 0; i < m; i++) {
                  ll x = vv[i].S.F;
                  ll y = vv[i].S.S;
                  ll cost = vv[i].F;
                  // cout << x << " " << y << endl;
                  // if(x == y) {
                  //       // cout << cost << endl;
                  //       ans += (cost > 0 ? cost : 0);
                  // }
                  x = find(x), y = find(y);
                  if (cost < 0) {
                        merge(x, y);
                        merged[ {x, y}] = 1;

                        continue;
                  }

                  if (x != y) {
                        merge(x, y);
                        merged[ {x, y}] = 1;
                  }
                  else {
                        // cout << cost << endl;
                        ans += cost;
                  }

            }
            cout << ans << endl;


      }

}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);


      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}