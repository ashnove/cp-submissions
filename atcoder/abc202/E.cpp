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

ll const inf = 1e15;
ll const mod = 1e9 + 7;
ll const maxn = 5e5 + 1;

vector<ll> adj[maxn];
vector<ll> atLevel[maxn];
ll vis[maxn], in[maxn], out[maxn], level[maxn];
ll timer = 0;
void dfs(ll from, ll d, ll par = -1) {

      in[from] = timer++;
      level[from] = d;
      atLevel[d].pb(from);
      for (ll to : adj[from]) {
            if (to != par) {
                  dfs(to, d + 1, from);
            }
      }

      out[from] = timer++;
}



void solve()
{
      ll t = 1;
      // cin >> t;

      for (ll tt = 1; tt <= t; tt++) {
            ll n; cin >> n;

            for (ll i = 2; i <= n; i++) {
                  ll x; cin >> x;
                  adj[x].pb(i);
            }
      }
      dfs(1, 0);

      ll q; cin >> q;
      while(q--){
            ll v, d; cin >> v >> d;

            if( level[v] > d ){
                  cout << 0 << endl;
            }
            else{

                  ll in_v = in[v], out_v = out[v];

                  ll low = 0, high = atLevel[d].size() - 1;

                  ll left = -1, right = -1;
                  while(low <= high){

                        ll mid = (low + high)/2;
                        ll cur = atLevel[d][mid];
                        ll cur_in = in[cur];

                        if( in_v <= cur_in ){
                              left = mid;
                              high = mid - 1;
                        }
                        else low = mid + 1;

                  }

                  low = 0, high = atLevel[d].size() - 1;
                  while(low <= high){

                        ll mid = (low + high)/2;
                        ll cur = atLevel[d][mid];
                        ll cur_out = out[cur];

                        if( out_v >= cur_out ){
                              right = mid;
                              low = mid + 1;
                        }
                        else high = mid - 1;



                  }
                  if(left == -1 || right == -1) cout << 0 << endl;
                  else cout << right - left + 1 << endl;

            }
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

