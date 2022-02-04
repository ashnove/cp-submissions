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
#define what_is(dp2) cerr << #dp2 << " is " << dp2 << endl;

using ldouble = long double;
using lint = long long int;
using ar = vector<lint>;
using mat = vector<vector<lint>>;
mat cn(lint n, lint m) {return vector<vector<lint>>(n, vector<lint>(m));}

lint const MOD = 1000000007;
bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<lint, pair<lint, lint>> &a, const pair<lint, pair<lint, lint>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
            return 1;
      return 0;
}
lint const inf = 1e18;
lint const maxn = 1e9 + 1;

void solve() {

      int tt1 = 1;
      // cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            int n; cin >> n;
            vector<int> a(n);
            for(int i = 0; i < n; i++){
                  cin >> a[i];
            }
            sort(all(a));
            vector<int> pf[(int)1e5 + 1];
            for(int i = 2; i <= 1e5; i++){
                  if(pf[i].size() == 0){
                        for(int j = i; j <= 1e5; j+=i)
                              pf[j].pb(i);
                  }
            }
            int ans = 1;
            vector<int> dp(1e5 + 1);
            for(int i = 0; i < n; i++){
                  int mx = 0;
                  for(int p: pf[a[i]]){
                        mx = max(mx, dp[p]);
                  }
                  for(int p: pf[a[i]]){
                        dp[p] = mx + 1;
                  }
                  ans = max(mx + 1, ans);
            }
            cout << ans << endl;
      }
}     

int main() {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      solve();
      // cout << "Case #" <<tt<<": ";
      return 0;
}
