#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
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
bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
            return 1;
      return 0;
}
ll const inf = 1e18;
ll const maxn = 1e9 + 1;
void solve() {

      int tt1 = 1;
      // cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            int  n, k, l, c, d, p, nll, np;
            cin >> n >> k >> l >> c >> d >> p >> nll >> np;
            // n friends;
            // k bottles
            // l ml per bottle
            // c limes cut into d slices
            // p gms salt
            // 1 toast = nl ml drink + 1 slice lime + np gms salt
            cout << min({k*l/nll, c*d, p/np}) / n;
      }
}     

int main() {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      solve();
      // cout << "Case #" <<tt<<": ";
      return 0;
}
