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

ll modpow(ll a, ll b)
{
      ll res = 1;
      while (b > 0) {
            if ( b & 1 ) res = ( res * a ) % MOD;
            a = ( a * a ) % MOD;
            b /= 2;
      }
      return res % MOD;
}
void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            ll n; cin >> n;
            ll a[n]; f(i,0,n) cin >> a[i];

            ll ans[n + 1] = {0};

            ll L[n], R[n]; //L[i] = value at pos < i which is strictly less than a[i];

            stack<ll> s;
            for(ll i = 0; i < n; i++){
                  while(!s.empty() && a[s.top()] >= a[i])
                        s.pop();
                  if(s.empty()) L[i] = -1;
                  else L[i] = s.top();
                  s.push(i);
            }
            while(!s.empty()) s.pop();
            for(ll i = n - 1; i >= 0; i--){
                  while(!s.empty() && a[s.top()] >= a[i])
                        s.pop();
                  if(s.empty()) R[i] = n;
                  else R[i] = s.top();
                  s.push(i);
            }

            for(ll i = 0; i < n; i++){
                  ll len = R[i] - L[i] - 1;
                  ans[len] = max(ans[len], a[i]);
            }
            for(ll i = n - 1; i >= 1; i--){
                  ans[i] = max(ans[i], ans[i + 1]);
            }

            for(ll i = 1; i <= n; i++)
                  cout << ans[i] << " ";
            nl;
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