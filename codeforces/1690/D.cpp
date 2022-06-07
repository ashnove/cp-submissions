#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l, r) uniform_int_distribution<long long>(l, r)(rng)
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
bool comp(const ll a, const ll b, int i, int j, int n){
      if(i == j - n){
            if(a < b)
                  return 1;
      }
      return 0;
}
ll const inf = 1e18;
ll const maxn = 1e5 + 1;
ll lcm(ll a, ll b){
      return (a*b) / __gcd(a, b);
}
ll sum(ll n){
      return n * (n + 1) / 2;
}

void solve() {

      int tt1 = 1;
      cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            ll n, k;
                cin >> n >> k;
                string s;
                cin >> s;
                
                ll ans = k;
                ll xx = 0, yy = 0;
                for(ll i = 0; i < k; i++) {
                    if(s[i] == 'B'){
                        xx++;
                  }
                    else {
                        yy++;
                  }
                }
                
                ans = min(ans, yy);
                for(ll i = k; i < n; i++) {
                    if(s[i-k] == 'B') {
                        xx--;
                  }
                    else {
                        yy--;
                  }                    
                    if(s[i] == 'B'){
                        xx++;
                  }
                    else {
                        yy++;
                  }
                    
                    ans  = min(ans, yy);
                }
                
                cout << ans << endl;
      }

}

int main() {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//    freopen("consistency_chapter_1_input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif
      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}