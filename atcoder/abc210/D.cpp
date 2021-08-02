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
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
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
int const madp2n = 5e5 + 1;



void solve()
{
      ll t1 = 1;
      // cin >> t1;
      for (ll tt = 1; tt <= t1; tt++) {
            ll n, m, c;
            cin >> n >> m >> c;
            vector<vector<ll>> a(n + 1, vector<ll> (m + 1, 0));
            vector<vector<ll>> dp1(n + 1, vector<ll> (m + 2, 0));
            vector<vector<ll>> dp2(n + 1, vector<ll> (m + 2, 0));
            ll ans = inf;

            for (ll i = 1; i <= n; i++)
                  for ( ll j = 1; j <= m; j++ )
                        cin >> a[i][j] ;

            for (ll i = 0; i <= n; i++) 
                  dp1[i][0] = inf;
            for (ll j = 0; j <= m; j++) 
                  dp1[0][j] = inf;
            
            for (ll i = 1; i <= n; i++)
                  for ( ll j = 1; j <= m; j++ )
                        dp1[i][j] = min( a[i][j], min(  dp1[i - 1][j], dp1[i][j - 1] ) + c );
            
            for ( ll i = 1; i <= n; i++ )
                  for ( ll j = 1; j <= m; j++ ){
                        dp2[i][j] = min( dp1[i - 1][j], dp1[i][j - 1] ) + c + a[i][j];
                        ans = min( ans, dp2[i][j] );
                  }
            
            for ( ll i = 0; i <= n; i++ ) 
                  dp1[i][m + 1] = inf;
            for ( ll j = 0; j <= m; j++ ) 
                  dp1[0][j] = inf;
            
            for ( ll i = 1; i <= n; i++ )
                  for ( ll j = m; j >= 1; j-- )
                        dp1[i][j] = min( a[i][j], min(  dp1[i - 1][j], dp1[i][j + 1] ) + c );
            
            for ( ll i = 1; i <= n; i++ )
                  for ( ll j = m; j >= 1; j-- ){
                        dp2[i][j] = min( dp1[i - 1][j], dp1[i][j + 1] ) + c + a[i][j];
                        ans = min( ans, dp2[i][j] );
                  }

                  
            cout << ans << endl;
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);


      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}