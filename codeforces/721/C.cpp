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
int const madp2n = 5e5 + 1;



void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            int n,m,T; cin >> n >> m >> T;
            vector<pair<int,int>> adj[n + 1];
            // vector<pair<int,int>> adj2[n + 1];
            for(int i = 0; i < m; i++){
                  int u,v,w; cin >>  u >> v >> w;
                  adj[u].pb({v, w});
                  // adj2[v].pb({u, w});
            }

            vector<vector<int>> dp(n + 1, vector<int> (n + 1, inf) );
            vector<vector<int>> par(n + 1, vector<int> (n + 1, -1) );
            // for(int i = 1; i <= n; i++) dp[i][1] = 0;
            dp[1][1] = 0;

            vector<ll> indc(n + 1, -1);
            for(int j = 1; j < n; j++){

                  for(int i = 1; i <= n; i++){
                        for(auto e : adj[i]){
                              ll to = e.F;

                              if(dp[to][j + 1] > dp[i][j] + e.S && dp[i][j] + e.S <= T){
                                    indc[to] = i;
                                    dp[to][j + 1] = dp[i][j] + e.S;
                                    par[to][j + 1] = i;
                              }
                        }
                  }

            }
            // for(ll i = 1; i <= n; i++){
            //       for(ll j = 1; j <= n; j++){
            //             cout << dp[i][j] << " ";
            //       }
            //       nl;
            // }
            int res = 0;
            for(int i = 1; i <= n; i++)
                  if(dp[n][i] <= T) res = i;

            vector<int> ans;
            int cur = n;
            int jumps = res;
            ans.pb(cur);
            while(jumps > 1){

                  ans.pb(par[cur][jumps]);
                  cur = par[cur][jumps];
                  jumps--;

            }
            // ans.pb(1);
            reverse(all(ans));
            cout << res << endl;
            for(ll i : ans) cout << i << " ";
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