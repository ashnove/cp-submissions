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
      // cin >> t;
      for (ll tt = 1; tt <= t; tt++) {
            ll n; cin >> n;

            ll a[n]; bool zer = 0;

            for (ll i = 0; i < n; i++) {
                  cin >> a[i];
                  if (a[i] == 0) zer = 1;
            }
            if (zer == 0) {
                  cout << -1 << endl;
                  continue;
            }
            vector<ll> pos[3];
            ll sum = 0;
            sort(a, a + n);
            reverse(a, a + n);
            for (int i = n - 1; i >= 0; i--) {
                  pos[a[i] % 3].pb(i);
                  sum += a[i];
            }

            bool block[n] = {0};
            if (sum % 3 == 0) {
                  if(a[0] == 0){
                        cout << 0 << endl;
                        continue;
                  }
                  for (ll i = 0; i < n; i++)
                        cout << a[i];
            }
            else {
                  bool ok = 1;
                  if ((sum % 3) == 1) {
                        if (pos[1].size() > 0)
                              block[pos[1][0]] = 1;
                        else if (pos[2].size() > 1)
                              block[pos[2][0]] = block[pos[2][1]] = 1;
                        else ok = 0;
                  }
                  else {
                        if (pos[2].size() > 0)
                              block[pos[2][0]] = 1;
                        else if (pos[1].size() > 1)
                              block[pos[1][0]] = block[pos[1][1]] = 1;
                        else ok = 0;
                  }

                  if (ok) {
                        vector<ll> ans;
                        for (ll i = 0; i < n; i++)
                              if (!block[i])
                                    ans.pb(a[i]);

                        if(ans[0] == 0){
                              cout << 0 << endl;
                              continue;
                        }
                        for (ll i : ans)
                              cout << i;


                  }
                  else cout << -1 << endl;

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