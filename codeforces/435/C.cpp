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

void solve() {

      int tt1 = 1;
      // cin >> tt1;
      // srand(time(0));
      for (int tt = 1; tt <= tt1; tt++) {
            int n; cin >> n;
            int width = 0, height = 0;
            int level = 0, max_level = 0, min_level = 0;
            vector<int> a(n);
            for(int i = 0; i < n; i++){
                  cin >> a[i];
                  width += a[i];
                  level += (i % 2 ? -a[i] : a[i]);
                  max_level = max(max_level, level); 
                  min_level = min(min_level, level); 
            }
            height = max_level - min_level;
            int height_pointer = height - abs(min_level) - 1;
            int width_pointer = 0;
            vector<vector<char>> cardio(height, vector<char>(width, ' '));
            for(int i = 0; i < n; i++){
                  while(a[i]--){
                        if(i % 2 == 0){
                              cardio[height_pointer][width_pointer] = '/';
                              height_pointer-=(a[i] > 0);
                              height_pointer = max(0, height_pointer);
                        }
                        else {
                              cardio[height_pointer][width_pointer] = '\\';
                              height_pointer+=(a[i] > 0);
                              height_pointer = min(height - 1, height_pointer);
                        }
                        width_pointer++;
                  }
            }

            for(int i = 0; i < height; i++){
                  for(int j = 0; j < width; j++){
                        cout << cardio[i][j] ;
                  }
                  cout << endl;
            }

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