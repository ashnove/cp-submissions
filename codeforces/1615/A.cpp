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

ll const inf = 1e18;
ll const maxn = 5e5+1;
 
vector<ll> adj[maxn];
ll vis[maxn],depth[maxn];
 
ll dp[maxn][20];
void dfs(ll x, ll d=0, ll par=-1)
{
      vis[x]=1;
      depth[x]=d;
      dp[x][0]=par;
      for(ll ch : adj[x])
            if(vis[ch]==0)
                  dfs(ch, d+1,x);
}
 
void lookup_table()
{
      for(ll j =1; j<20; j++ ){
            for(ll i = 1; i<maxn; i++){
 
                  if(dp[i][j-1]!=-1){
                        ll par = dp[i][j-1];
                        dp[i][j] = dp[par][j-1];
                  }
 
            }
      }
}
 
ll lca(ll a, ll b,ll jump=0)
{
 
      if(depth[a]>depth[b] && a!=-1)swap(a,b);
      if(a!=-1) jump = depth[b]-depth[a];
      
      while(jump>0){
            ll i = log2(jump);
            b = dp[b][i];
            jump -= (1<<i);
      }
      if(a==-1) return b;
      if(a==b) return a;
 
      for(ll i = 19; i>=0; i--){
            if( dp[a][i]!=-1 && dp[a][i]!=dp[b][i] )
                  a = dp[a][i], b = dp[b][i];
      }
 
      return dp[b][0];
}
void solve() {

      int tt1 = 1;
      cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            int n; cin >> n;
            ll sum = 0;
            vector<ll> a(n);
            for(int i = 0; i < n; i++) { cin >> a[i]; sum += a[i]; }
            
            cout << (sum % n != 0) << endl; 
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