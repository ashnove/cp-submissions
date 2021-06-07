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
ll const maxn = 1e5 + 1;
vector<ll> adj[maxn];
ll dp[maxn];

ll dfs(ll from){

      ll ch = 0;
      for(ll to : adj[from]){
            ch++;
            if(dp[to] == -1)
                  dp[to] = dfs(to);
            dp[from] = max(dp[from], 1 + dp[to]);
      }

      if(ch == 0) return 0;
      else return dp[from];

}

void solve()
{
      ll t1 = 1;
      // cin >> t;
      for (ll tt = 1; tt <= t1; tt++) {
            ll n; cin >> n;

            ll a[n + 1]; 
            ll b[n + 1]; 
            ll c[n + 1]; 
            f(i,0,n) cin >> a[i + 1] >> b[i + 1] >> c[i + 1];

            a[0]=b[0]=c[0] = 0;

            ll dp[n + 1][3] = {0};
            dp[1][0] = a[1];
            dp[1][1] = b[1];
            dp[1][2] = c[1];

            for(ll i = 2; i <= n; i++){
                  dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]); 
                  dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]); 
                  dp[i][2] = c[i] + max(dp[i - 1][1], dp[i - 1][0]); 
            }
            
            cout << max({dp[n][0], dp[n][1], dp[n][2]});
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

