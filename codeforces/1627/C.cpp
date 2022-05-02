#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l, r) uniform_int_distribution<long long>(l, r)(rng)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define Th third
#define nl cout << endl;
#define endl "\n";
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(dp2) cerr << #dp2 << " is " << dp2 << endl;

using lld = long double;
using ll = long long int;
using ar = vector<ll>;
using mat = vector<vector<ll>>;
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}

ll const MOD = 1000000007;
bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
            return 1;
      return 0;
}
bool comp(const ll a, const ll b, int i, int j, int n){
      if(i == j - n){
            if(a < b)
                  return 1;
      }
      return 0;
}
ll const inf = 1e18;
ll const maxn = 1e5 + 1;
vector<int> adj[maxn];
vector<int> vis(maxn, 0);
map<pair<int,int>,int> mark;
void dfs(int from, int last){
      vis[from] = 1;
      for(int to : adj[from]){
            if(!vis[to]){
                  mark[{from, to}] = mark[{to, from}] = (last == 2 ? 3 : 2);
                  dfs(to, (last == 2 ? 3 : 2));
            }
      }
}
void solve() {

      int tt1 = 1;
      cin >> tt1;
      // srand(time(0));
      for (int tt = 1; tt <= tt1; tt++) {
            int n; cin >> n;
            mark.clear();
            for(int i = 0; i <= n; i++){
                  adj[i].clear(), vis[i] = 0;
            }
            int start = 0, possible = 1;
            vector<int> degree(n + 1, 0);
            vector<pair<int,int>> edgs;
            for(int i = 0; i < n - 1; i++){
                  int u,v; cin >> u >> v;
                  edgs.pb({u,v});
                  adj[u].pb(v);
                  adj[v].pb(u);
                  degree[u]++, degree[v]++;
                  if(degree[u] > 2 || degree[v] > 2) possible = 0;
            }
            for(int i = 1; i <= n; i++) if(degree[i] == 1) start = i;
            if(!possible){
                  cout << -1 << endl;
                  continue;
            }
            // cout << start << endl;
            dfs(start, 3);    
            for(auto e : edgs){
                  cout << mark[e] <<  " ";
            }
            cout << endl;

      }

}

int main() {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//    freopen("consistency_chapter_1_input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif


      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}