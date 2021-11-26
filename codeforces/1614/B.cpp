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
ll const maxn = 1e5 + 1;

ll gcd(ll a, ll b) {
      if (a == 0)
            return b;
      return gcd(b % a, a);
}


void solve() {

      int tt1 = 1;
      cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            ll n; cin >> n;
            vector<ll> a(n);
            for(ll  i = 0; i < n; i++) cin >> a[i];

            vector<ll> b(n);
            iota(all(b), 0);
            sort(all(b), [&](ll i, ll j){
                  return a[i] < a[j];
            });
            vector<ll> ans(n);
            ll it = 1, res = 0;
            reverse(all(b));
            for(ll i = 0; i < n; i+=2){
                  ans[b[i]] = it; res += 2*a[b[i]]*it;
                  if(i + 1 < n) ans[b[i + 1]] = -it, res += 2*a[b[i + 1]]*it;
                  it++;
            }
            cout << res << endl;
            cout << 0 << " ";
            for(ll i : ans) cout << i << " ";
            cout << endl;
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