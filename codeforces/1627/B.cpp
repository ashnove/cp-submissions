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
int dis(int n, int m, int x, int y){
    return abs(n - x) + abs(m - y);
}
int getDis(int n, int m, int x, int y){
    return max(max(dis(0, 0, x, y), dis(0, m, x, y)), max(dis(n, 0, x, y), dis(n, m, x, y)));
}
void solve() {

      int tt1 = 1;
      cin >> tt1;
      // srand(time(0));
      for (int tt = 1; tt <= tt1; tt++) {
            int n, m;
            cin >> n >> m;
            vector<int> a;
            for(int i = 0; i < n; ++i){
                  for(int j = 0; j < m; ++j){
                        a.pb(getDis(n - 1, m - 1, i, j));
                  }
            }
            sort(all(a));
            for(int i = 0; i < n * m; i++){
                  cout << a[i] << " ";
            }
            cout << endl;
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