/*
* @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define Th third
#define nl cout << endl;
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(x) cerr << #x << " is " << x << endl;

using lld = long double;
using ll = int;
using ar = vector<ll>;
using mat = vector<vector<ll>>;
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}

ll const MOD = 1e9 + 7;
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0;}
template<class T> inline void add(T &a, T b) { a += b; a >= MOD ? a - MOD : a; }
template<class T> inline void sub(T &a, T b) { a -= b; a < 0 ? a + MOD : a; }
template<class T> inline void mul(T &a, T b) {return (a * b) % MOD; }
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

// ll const inf = 1e18;
// ll const mod = 1e9 + 7;
// int const maxn = 2e5 + 1;
ll pp = 0;
ll a, b; 
ll calc(ll n, ll t){

      ll ans = 1;
      ll cnt = 0;
      while(n > 1 && (n % 2) == 0){
            n/=2;
            if(t && b > 1 && (b % 2) == 0) pp++, b/=2;
            cnt++;
      }
      // ans *= (cnt + 1);
      for(ll i = 3; i * i <= n; i+=2){
            ll cur = 0;
            while( n > 1 && (n % i) == 0){
                  n/=i;
                  if(t && b > 1 && (b % i)==0) pp++, b/=i;
                  cnt++;
            }
            // cur++;
            // ans *= cur;
      }
      if(n > 2)
            cnt++;


      return cnt;

}

void solve()
{
      ll t1 = 1;
      cin >> t1;

      for (ll tt = 1; tt <= t1; tt++) {
            cin >> a >> b;
            ll k; cin >> k;
            if(a == b && k == 1){
                  cout << "NO\n";
                  continue;
            }
            ll A = max(a, b);
            ll B = min(a,b);
            if( A % B == 0 && k == 1){
                  cout << "YES\n";
                  continue;
            }
            pp = 0;
            ll r = calc(a, 1) ;
            ll s = pp + calc(b, 0) ;


            // r-=2;
            // cout << r << endl;
            r+=s;
            cout << ( k >= 2 && k <= r ? "YES\n" : "NO\n");
      }


}


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      /*
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif/**/

      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}