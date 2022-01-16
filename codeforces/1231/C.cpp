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
            int n, m; cin >> n >> m;
            vector<vector<int>> a(n, vector<int>(m ,0));
            for(int i = 0; i < n; i++){
                  for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                  }
            }
            bool ok = 1;
            int sum = 0;
            for(int i = n - 1; i >= 0; i--){
                  for(int j = m - 1; j >= 0; j--){
                        if(i + 1 < n && j + 1 < m){
                              if(a[i][j] == 0){
                                    a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1;
                              }
                              else {
                                    if(a[i + 1][j] <= a[i][j] || a[i][j + 1] <= a[i][j]){
                                          ok = 0;
                                    }
                              }
                        }
                        else if(i + 1 < n){
                              if(a[i][j] == 0)
                                    a[i][j] = a[i + 1][j] - 1;
                              else {
                                    if(a[i][j] >= a[i + 1][j]){
                                          ok = 0;
                                    }
                              }
                        }
                        else if(j + 1 < m){
                              if(a[i][j] == 0){
                                    a[i][j] = a[i][j + 1] - 1;
                              }
                              else {
                                    if(a[i][j] >= a[i][j + 1]){
                                          ok = 0;
                                    }
                              }
                        }
                        sum += a[i][j];
                  }
            }
            if(ok){
                  cout << sum << endl;
            }
            else {
                  cout << -1 << endl;
            }
      }
}

int main() {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      solve();
      // cout << "Case #" <<tt<<": ";
      return 0;
}
