/*
* @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(dp2) (dp2).begin(),(dp2).end()
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
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmadp2(T &a, T b) { return a < b ? a = b, 1 : 0;}
template<class T> inline void add(T &a, T b) { a += b; a >= MOD ? a - MOD : a; }
template<class T> inline void sub(T &a, T b) { a -= b; a < 0 ? a + MOD : a; }
template<class T> inline void mul(T &a, T b) {return (a * b) % MOD; }
template<typename T> ostream& operator <<(ostream &out, const vector<T> &v) { for (auto &dp2 : v) out << dp2 << ' '; return out;}
template<class T> void remDup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), end(v)); }

bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<ll, ll> &a, const pair<ll, ll> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S < b.S)
            return 1;
      return 0;
}
class Pair { public: ll first, second;};
bool comp3(const Pair &a, const Pair &b) {
      if (a.F > b.F) return 1; return 0;
}
class Trips { public: ll first, second, third;};
bool comp4(const Trips &a, const Trips &b) {
      if (a.Th > b.Th) return 1; return 0;
}

void readArray(ll a[], int n) {
      for (ll i = 0; i < n ; i++)
            cin >> a[i];
}

ll const inf = 1e18;
ll const maxn = 1e5 + 1;

ll gcd(ll a, ll b) {
      if (a == 0)
            return b;
      return gcd(b % a, a);
}
ll modpow(ll a, ll b) {
      ll res = 1;
      while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
      }
      return res;
}

void solve() {

      int tt1 = 1;
      // cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            ll n, m; cin >> n >> m;

            string s[2*n];
            f(i, 0, 2*n) cin >> s[i];

            vector<pair<ll,ll>> ranks;
            for(ll i = 0; i < 2*n; i++){
                  ranks.pb({0, i});
            }
            for (ll j = 0; j < m; j++) {
                  for (ll i = 0; i < 2*n - 1; i+=2) {

                        ll s1 = ranks[i].S;
                        ll s2 = ranks[i + 1].S;
                        char s1T = s[s1][j];
                        char s2T = s[s2][j];
                        if(s1T=='G' && s2T == 'C')
                              ranks[i].F++;
                        if(s1T=='C' && s2T == 'G')
                              ranks[i + 1].F++;

                        if(s1T=='G' && s2T == 'P')
                              ranks[i + 1].F++;
                        if(s1T=='P' && s2T == 'G')
                              ranks[i].F++;

                        if(s1T=='P' && s2T == 'C')
                              ranks[i + 1].F++;
                        if(s1T=='C' && s2T == 'P')
                              ranks[i].F++;
                  }
                  sort(all(ranks), comp2);
                  // reverse(all(ranks));

                  // for(auto i : ranks) cout << i.F <<"|"<< i.S+1  << " "; nl;
            }

            vector<ll> hash(2*n);
            for(ll i = 0; i < 2*n; i++){
                  hash[ranks[i].S] = i + 1;
            }

            for(ll i = 0; i < 2*n ; i++)
                  cout << ranks[i].S + 1 << endl;
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