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


string afterOneRun(string s, int m){
      string Hx = s.substr(0, 2);
      string My = s.substr(3, 2);
      int H = stoi(Hx);
      int M = stoi(My);

      M = M + m;
      int c = M / 60;
      M %= 60;
      H += c;
      H %= 24;

      string HH = to_string(H);
      string MM = to_string(M);
      if(HH.size() == 1) HH = '0' + HH;
      if(MM.size() == 1) MM = '0' + MM;
      return HH +":" + MM;
}

bool isPalin(string b){
      string a = b;
      reverse(all(b));
      return a == b;
}

void solve() {

      int tt1 = 1;
      cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            ll n; cin >> n;
            ll s; cin >> s;
            vector<ll> a(n);
            for(ll i =0; i< n; i++){
                  cin >> a[i];
            }
            map<ll,pair<ll,ll>> cnt;
            cnt[0] = {1, -1};
            ll sum = 0;
            ll ans = LLONG_MAX;
            bool ok = 0;
            for(ll i = 0; i < n; i++){
                  sum += a[i];
                  ll need = sum - s;
                  if(cnt[need].first != 0){
                        ok = 1;
                  }
                  if(need == 0){
                        ans = min(ans, n - i - 1);
                  }
                  else {
                        ll L = cnt[need].second + 1;
                        ans = min(ans, L + n - i - 1);
                  }
                  if(cnt[sum].first == 0){
                        cnt[sum].first = 1;
                        cnt[sum].second = i;
                  }
            }

            cout << (ok ? ans:-1) << endl;
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