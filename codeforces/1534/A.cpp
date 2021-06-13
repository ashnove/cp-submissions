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
ll const maxn = 1e5 + 1;
      
ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};
ll vis[55][55];
ll a[55][55];
ll n,m;
bool isValid(ll x,ll y){
      return (x>=0 && x<n && y>=0 && y < m);
}
void dfs(ll i, ll j, ll val){

      vis[i][j] = 1;
      a[i][j] = val;
      for(ll p = 0; p < 4; p++){
            ll x =  i+ dx[p], y = j + dy[p];

            if( isValid(x, y) && !vis[x][y] && (a[x][y]==0 || a[x][y] == (val==1?2:1))){
                  dfs(x, y, (val==1?2:1));
            }

      }

}

void solve()
{
      ll t1 = 1;
      cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            cin >> n >> m;
            memset(vis, 0, sizeof vis);
            string s[n];
            f(i,0,n) cin >> s[i];

            f(i,0,n){
                  f(j,0,m)
                        a[i][j] = (s[i][j] == 'R' ? 1 : (s[i][j] == 'W'? 2 : 0));
            }
            bool ok2 = 0;
            f(i,0,n){
                  f(j,0,m){
                        if(!vis[i][j] && a[i][j] != 0){
                              dfs(i, j, a[i][j]);
                              ok2 = 1;
                        }
                  }
            }
            if(!ok2){
                  dfs(0,0,1);
            }

            bool ok = 1;
            f(i,0,n)f(j,0,m)if(a[i][j] == 0) ok = 0;
            f(i,0,n){
                  f(j,0,m){

                        if(i+1<n && a[i+1][j]==a[i][j]) ok = 0;
                        if(j+1<m && a[i][j+1]==a[i][j]) ok = 0;
                        if(i-1>=0 && a[i-1][j]==a[i][j]) ok = 0;
                        if(j-1>=0 && a[i][j-1]==a[i][j]) ok = 0;

                  }
            }

            if(ok){
                  cout << "YES\n";
                  f(i,0,n){
                        f(j,0,m){
                              cout << (a[i][j] == 1 ? 'R':'W');
                        }nl;
                  }
            }
            else cout << "NO\n";
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