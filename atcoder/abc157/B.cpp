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


            map<ll, ll> row, col, pres;
            for (ll i = 0; i < 3; i++) {
                  for (ll j = 0; j < 3; j++) {
                        ll x; cin >> x;
                        row[x] = i;
                        col[x] = j;
                        pres[x] = 1;
                  }
            }

            ll mark[3][3];
            memset(mark, 0, sizeof mark);
            ll n; cin >> n;

            for (ll i = 0; i < n; i++) {
                  ll x; cin >> x;
                  if(pres[x])
                  mark[row[x]][col[x]] = 1;
            }
            // for(ll i = 0; i < 3; i++){
            //       for(ll j = 0; j < 3; j++)
            //             cout << mark[i][j] << " "; nl
            // }
            bool ok = 0;
            for (ll i = 0; i < 3; i++) {
                  if(mark[i][0] + mark[i][1] + mark[i][2] == 3)ok = 1;
                  if(mark[0][i] + mark[1][i] + mark[2][i] == 3)ok = 1;
                  if(i == 0)
                        if(mark[i][0] + mark[i + 1][1] + mark[i + 2][2] == 3) ok  = 1;
                  if(i == 2)
                        if(mark[i - 2][2] + mark[i - 1][1] + mark[i][0] == 3 ) ok = 1;
            }
            cout << (ok ? "Yes\n" : "No");
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

