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

ll dis(ll a, ll b, ll c, ll d){
      return abs(a - c) + abs(b - d);
}
void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            ll n; cin >> n;

            ll a[n + 1][n + 1];
            
            f(i,0,n) f(j,0,n){
                  cin >> a[i + 1][j + 1];
            }
            set<pair<ll,ll> > s;
            for(ll i = 1; i <= n; i++){
                  for(ll j = 1; j <= n; j++)
                        if(i != j)s.insert({i, j});
            }
            bool ok = 1;
            for(ll k = 1; k <= n; k++){
                  for(ll i = 1; i <= n; i++){
                        for(ll j = 1; j <= n; j++){
                              if(i != k && j != k && a[i][j] == a[i][k] + a[k][j]){
                                    s.erase({i ,j});
                              }
                              if(i != k && j != k && a[i][j] > a[i][k] + a[k][j]){
                                    ok = 0;
                              }
                        }
                  }
            }
            ll ans = 0;
            set<ll> c;
            for(ll i = 1; i <= n; i++){
                  for(ll j = i + 1; j <= n; j++){
                        if(s.count({i , j}) || s.count({j ,i})){
                              c.insert(i);
                              c.insert(j);
                              ans += a[i][j];
                        }
                  }
            }
            cout << (ok ? ans : -1 ) << endl;
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