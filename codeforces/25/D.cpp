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

ll const MOD = 1e9 + 7;
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
ll const mod = 1e9 + 7;
ll const maxn = 1e3 + 1;

vector<ll> adj[maxn];
vector<ll> parent(maxn, -1);
vector<ll> Rank(maxn, 1);
queue<pair<ll,ll>> back_edges;

ll find(ll x) {
      if (parent[x] < 0)
            return x;
      return parent[x] = find(parent[x]);
}
void merge(ll a, ll b) {
      a = find(a), b = find(b);
      if (a == b) return;
      if (Rank[a] > Rank[b]) {
            parent[b] = a;
            Rank[a] += Rank[b];
      }
      else {
            parent[a] = b;
            Rank[b] += Rank[a];
      }
}
ll vis[maxn];
map<pair<ll,ll>, bool > used;
void dfs(ll from, ll par = -1){
      vis[from] = 1;
      for(ll to : adj[from]){
            if(vis[to] && to != par){
                  if(!used[{to, from}]){
                        used[{from, to}] =1;
                        back_edges.push({from, to});
                  }
            }
            if(!vis[to])
                  dfs(to, from);
      }
}
void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            ll n; cin >> n;
            for (ll i = 0; i < n - 1; i++) {
                  ll u, v; cin >> u >> v;
                  adj[u].pb(v);
                  adj[v].pb(u);
                  merge(u, v);
            }
            vector<ll> nodes;
            for (ll i = 1; i <= n; i++) if (parent[i] < 0) nodes.pb(i);
            cout << nodes.size() - 1 << endl;

            for(ll i = 0; i < nodes.size(); i++){
                  dfs(nodes[i]);
            }
            // cout << back_edges.size() << endl;
            // while(!back_edges.empty()){
            //       cout << back_edges.front().F << " " << back_edges.front().S << endl;
            //       back_edges.pop();
            // }
            for (ll i = 1; i < nodes.size(); i++) {
                  ll u = nodes[i - 1], v = nodes[i];
                  cout << back_edges.front().F << " " << back_edges.front().S << " ";
                  back_edges.pop();
                  cout << u << " " << v << endl;
            }

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