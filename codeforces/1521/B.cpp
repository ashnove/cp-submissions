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
ll const maxn = 5e5 + 1;


void solve()
{
      ll t = 1;
      cin >> t;
      for (ll tt = 1; tt <= t; tt++) {
            ll n; cin >> n;

            ll minVal = inf;
            ll a[n]; f(i, 0, n) {cin >> a[i]; chmin(minVal, a[i]);}
            ll ind = -1;
            for (ll i = 0; i < n; i++)
                  if (a[i] == minVal) ind = i;
            // cout << ind << endl;

            vector<ll> ops[n + 1];
            ll it = 0;
            ll pq = 1;
            for (ll i = ind + 1; i < n; i++) {
                  ll x = a[ind];
                  ll y = x + pq++;
                  a[i] = y;
                  ops[it].pb(ind + 1);
                  ops[it].pb(i + 1);
                  ops[it].pb(x);
                  ops[it].pb(y);
                  it++;
            }

            ll pp = 1;
            for (int i = ind - 1; i >= 0; i--) {
                  ll x = a[ind];
                  ll y = x + pp++;;
                  a[i] = y;
                  ops[it].pb(ind + 1);
                  ops[it].pb(i + 1);
                  ops[it].pb(x);
                  ops[it].pb(y);
                  it++;
            }     
            cout << it << endl;
            // for(int i = 0; i < n; i++)
            //       cout << a[i] << " "; nl;
            for (ll i = 0; i < it; i++) {

                  cout << ops[i][0] << " " << ops[i][ 1] << " " << ops[i][ 2] << " " << ops[i][ 3] << endl;
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