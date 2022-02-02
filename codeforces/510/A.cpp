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
            int n,m; cin >> n >> m;
            vector<string> v(n);
            for(int i = 0; i < n; i++){
                  for(int j = 0; j < m; j++){
                        v[i]+='.';
                        if(i%2==0)v[i].back()='#';
                  }
                  if(i/2 & 1) v[i].front() = '#';
                  else v[i].back() = '#';
            }
            for(int i = 0; i < n; i++){
                  cout << v[i] << endl;
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
