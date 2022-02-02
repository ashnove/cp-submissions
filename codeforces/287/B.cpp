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
ll sum(ll n){
      return n * (n + 1) / 2;
}
void solve() {

      int tt1 = 1;
      // cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            ll n, k; cin >> n >> k;
            if(n == 1){
                  cout << 0 << endl;
                  continue;
            }
            ll low = 1, high = k - 1;
            ll ans = 0;
            while(low <= high){
                  ll mid = low + (high - low) / 2;
                  ll S = sum(k - 1) - sum(mid - 1);
                  // bool extra = (S!=n-1 && n - 1 - S < mid);
                  ll rem = n - 1 - S;
                  if(rem < mid){
                        ans = k - mid + (rem != 0);
                        low = mid + 1;
                  }
                  else {
                        high = mid - 1;
                  }
            }
            cout << (ans == 0 ? -1 : ans) << endl;
      }
}     

int main() {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      solve();
      // cout << "Case #" <<tt<<": ";
      return 0;
}
