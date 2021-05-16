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
ll const maxN = 5e5 + 1;

void solve()
{
      ll t = 1;
      // cin >> t;
      for (ll tt = 1; tt <= t; tt++) {
            
            vector<ll> s, ns;
            ll N; cin >> N;
            for(ll i = 0; i < N; i++){
                  ll x; cin >> x;
                  if(x) s.pb(i);
                  else ns.pb(i);
            }
            ll n = ns.size();
            ll m = s.size();
            ll dp[n + 1][m + 1];

            for(ll i = 0; i <= n; i++){

                  for(ll j = 0; j <= m; j++){

                        if(j > i) dp[i][j] = inf;
                        else if(i == 0){
                              dp[i][j] = 0;
                        }
                        else if(j == 0 || dp[i- 1][j- 1]==inf){
                              dp[i][j] = dp[i-1][j];
                        }
                        else {
                              dp[i][j]= min( dp[i-1][j],  dp[i-1][j-1] + abs(ns[i - 1] - s[j - 1]) );
                        }

                  }
            }

            ll ans = inf;

            for(ll i = 1; i <= n; i++){
                  // cout << dp[i][n] << endl;
                  ans = min(ans, dp[i][m]);
            }

            // for(ll i = 1; i <= n; i++){
            //       for(ll j = 1; j <= m; j++){
            //             cout << dp[i][j] << " ";
            //       }
            //       nl;
            // }
            cout << ans << endl;
      }

}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      //*
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif/**/

      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}

