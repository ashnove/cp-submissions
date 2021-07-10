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
      cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            ll k, n, m; cin >> k >> n >> m;

            vector<ll> a(n);
            vector<ll> b(m);

            f(i,0,n) cin >> a[i];
            f(i,0,m) cin >> b[i];

            ll i = 0, j = 0;
            vector<ll> ans;
            bool ok = 1;
            while(i < n && j < m){
                  if(a[i] == 0)
                        ans.pb(a[i]), k++, i++;
                  else if(b[j] == 0)
                        ans.pb(b[j]), k++, j++;
                  

                  else if(a[i] < b[j]){
                        if(a[i] > k) ok = 0;
                        else ans.pb(a[i]),i++;
                  }
                  else{
                        if(b[j] > k) ok = 0;
                        else ans.pb(b[j]) ,j++;
                  }
                  if(!ok) break;
            }
            if(!ok){
                  cout << -1 << endl;
                  continue;
            }
            while(i < n){
                  if(a[i] == 0) ans.pb(a[i]), k++;
                  else if(a[i] > k) ok = 0;
                  else ans.pb(a[i]);

                  i++;
                  
            }

            while(j < m){
                  if(b[j] == 0) ans.pb(b[j]), k++;
                  else if(b[j] > k) ok = 0;
                  else ans.pb(b[j]);

                  j++;
            
            }

            if(ok){
                  for(auto e : ans) cout << e << " ";
                  nl;
            }
            else cout <<"-1\n";

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