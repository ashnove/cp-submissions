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
ll const maxn = 5e5 + 1;


void solve()
{     ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {


            ll n, l, x, y; cin >> n >> l >> x >> y;

            ll a[n]; for (ll i = 0; i < n; i++) cin >> a[i];

            ll cnt = 0;
            map<ll, ll> pres;
            ll sum = 0;
            bool xx = 0, yy = 0;
            pres[0] = 1;
            for (ll i = 1; i < n; i++) {

                  ll req1 = a[i] - x;
                  ll req2 = a[i] - y;
                  // if(i == n - 1) cout << req1
                  if (pres[req1]) xx = 1;
                  if (pres[req2]) yy = 1;
                  pres[a[i]] = 1;

            }
            if (xx && yy) {
                  cout << 0 << endl;
                  continue;
            }
            ll pos = -1;
            if (xx == 0 && yy == 0) {

                  if (x == y) {
                        for (ll i = 1; i < n; i++) {
                              if (a[i] - x >= 0) {
                                    pos = a[i] - x;
                              }
                        }
                  } else {
                        map<ll, ll> dY, dX;
                        for (ll i = 0; i < n; i++) {
                              if (a[i] + y <= l) dY[a[i] + y] = 1;
                              if (a[i] - y >= 0) dY[a[i] - y] = 1;

                        }

                        for (ll i = 0; i < n; i++) {
                              if (a[i] + x <= l) if (dY[a[i] + x]) pos = a[i] + x;
                              if (a[i] - x >= 0) if (dY[a[i] - x]) pos = a[i] - x;
                        }

                  }
            }
            if (pos != -1) {
                  cout << "1\n";
                  cout << pos << endl;
                  continue;
            }
            vector<ll> ans;
            for (ll i = 1; i < n; i++) {

                  ll req1 = a[i] - x;
                  ll req2 = a[i] - y;

                  if (!xx && req1 > 0) {ans.pb(req1); xx = 1;}
                  if (!yy && req2 > 0) {ans.pb(req2); yy = 1;}

            }
            cout << ans.size() << endl;;
            for (ll i : ans) cout << i << " ";

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
