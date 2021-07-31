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
int const maxn = 5e5 + 1;



void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            int n,m; cin >> n >> m;

            vector<ll> dp(n + 1, 0), dis(n + 1, inf);

            vector<int> adj[n + 1];
            for(int i = 0; i < m; i++){
                  int x, y; cin >> x >> y;
                  adj[x].push_back(y);
                  adj[y].push_back(x);
            }
            priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
            q.push({0, 1});
            dis[1] = 0;
            dp[1] = 1;
            while(!q.empty()){
                  int cur = q.top().S;
                  int d = q.top().F;
                  q.pop();
                  if(dis[cur] < d) continue;

                  for(auto to : adj[cur]){
                        if( d + 1 < dis[to] ){
                              dp[to] = dp[cur];
                              dis[to] = d + 1;
                              q.push({dis[to], to});
                        }
                        else if(d + 1 == dis[to]){
                              // cout << " (" << cur << " " << to << ") \n";
                              dp[to] = (dp[to] + dp[cur]) % MOD;
                        }
                  }
            }

            cout << dp[n] << endl;
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