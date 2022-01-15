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
ll const maxn = 2e5 + 1;
void solve() {

      int tt1 = 1;
      // cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            int n,k,q; cin >> n >> k >> q;
            int max_temp = maxn;
            vector<int> hash(max_temp + 2, 0);
            vector<pair<int,int>> store;
            for(int i = 0; i < n; i++){
                  int a,b; cin >> a >> b;
                  hash[a]++;
                  hash[b + 1]--;
            }
            vector<int> cnt(max_temp + 1, 0);
            for(int i = 1; i < max_temp + 1; i++) {
                  hash[i] += hash[i - 1];
                  cnt[i] += cnt[i - 1];
                  if(hash[i] >= k)cnt[i]++;
            }
            for(int i = 0; i < q; i++){
                  int a,b; cin >> a >> b;
                  cout << cnt[b] - cnt[a - 1] << endl;
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
