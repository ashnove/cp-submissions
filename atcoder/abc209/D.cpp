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
template<typename T> ostream& operator <<(ostream &out, const vector<T> &v) { for (auto &x : v) out << x << ' '; return out;}
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
int const maxn = 1e5 + 1;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

vector<int> adj[maxn];
int d = 0;
int dp[maxn][20], depth[maxn];
void dfs(int from, int dd = 0, int par = -1) {
      dp[from][0] = par;
      depth[from] = dd;
      for (int to : adj[from]) {
            if (par != to)
                  dfs(to, dd + 1, from);
      }
}

void lookup_table(int n)
{
      for (int j = 1; j < 20; j++ ) {
            for (int i = 1; i <= n; i++) {

                  if (dp[i][j - 1] != -1) {
                        int par = dp[i][j - 1];
                        dp[i][j] = dp[par][j - 1];
                  }

            }
      }
}

int lca(int a, int b, int jump = 0)
{

      if (depth[a] > depth[b] && a != -1)swap(a, b);
      if (a != -1) jump = depth[b] - depth[a];

      while (jump > 0) {
            int i = log2(jump);
            b = dp[b][i];
            jump -= (1 << i);
      }
      if (a == -1) return b;
      if (a == b) return a;

      for (int i = 19; i >= 0; i--) {
            if ( dp[a][i] != -1 && dp[a][i] != dp[b][i] )
                  a = dp[a][i], b = dp[b][i];
      }

      return dp[b][0];
}

void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {

            int n; cin >> n;
            int q; cin >> q;

            for (int i = 0; i <= n; i++) for (int j = 0; j < 20; j++) dp[i][j] = -1;
            for (int i = 0; i < n - 1; i++) {
                  int u, v; cin >> u >> v;
                  adj[u].pb(v);
                  adj[v].pb(u);
            }
            d = 0;
            dfs(1);
            lookup_table(n);
            while (q--) {
                  int c,d; cin >> c >> d;
                  int dad = lca(c,d);
                  ll dis = depth[c] + depth[d] - 2*depth[dad];
                  dis += 1;
                  if(dis & 1) cout << "Town\n";
                  else cout << "Road\n";
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