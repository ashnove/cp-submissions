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
int const maxn = 3e5 + 1;

void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            ll n,m,r; cin >> n >> m >> r;
            vector<ll> R(r);
            f(i,0,r) cin >> R[i];
            vector<vector<ll>> dis(n + 1 , vector<ll>(n + 1, inf));
            for(ll i = 1; i <= n; i++) dis[i][i] = 0;
            for(ll i = 0; i < m; i++){
                  ll a, b, c; cin >> a >> b >> c;
                  chmin(dis[a][b], c);
                  chmin(dis[b][a], c);
            }
            for(ll i = 0; i <= n; i++) dis[i][i] = 0;
            for(ll k = 1; k <= n; k++){
                  for(ll i = 1; i <= n; i++){
                        for(ll j = 1; j <= n; j++){
                              dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        }
                  }
            }

            ll dp[1<<r][r];
            memset(dp, 0x3f, sizeof dp);
            ll it = 1;
            for(ll i = 0; i < r; i++)
                  dp[1 << i][i] = 0;

            for(ll i = 1; i < (1 << r); i++){

                  for(ll j = 0; j < r; j++){

                        if(i & (1 << j)){

                              for(ll k = 0; k < r; k++){
                                    if(!(i & (1 << k))){
                                          if(dis[R[j]][R[k]] < inf)
                                          dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dis[R[j]][R[k]] + dp[i][j]);
                                    }
                              }

                        }

                  }

            }
            ll ans = inf;
            for(ll i = 0; i < r; i++)
                  chmin(ans, dp[(1 << r) - 1][i]);
            
            cout << ans<< endl;

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