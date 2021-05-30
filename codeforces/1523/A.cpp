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
using ll = long long int;
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

ll const inf = 1e15;
ll const mod = 1e9 + 7;
ll const maxn = 5e5 + 1;


void solve()
{
      ll t = 1;
      cin >> t;
      for (ll tt = 1; tt <= t; tt++) {
            ll n,K; cin >> n >> K;

            string s; cin >> s;

            ll a[n];
            f(i,0,n){
                  a[i] = (s[i]=='1'? 1:0); 
            }

            vector<ll> vv;
            for(ll i = 0; i < n; i++){
                  if(a[i])
                        vv.pb(i);
            }

            for(ll i = 1; i < vv.size(); i++){
                  if(vv[i] - vv[i - 1] >= 3){
                        ll p = vv[i - 1], q = vv[i];
                        if(p + K >= q - K){
                              ll d = q - p - 1;
                              ll L = d/2;
                              ll R = d/2;
                              if(d % 2 == 0){
                                    R++;
                              }
                              for(ll k = p + 1; k <= p + L; k++)
                                    a[k] = 1;
                              for(ll k = q - 1; k >= q - R; k--)
                                    a[k] = 1;

                        }
                        else{
                              for(ll k = p + 1; k <= p + K; k++)
                                    a[k] = 1;
                              for(ll k = q - 1; k >= q - K; k--)
                                    a[k] = 1;
                        }
                  }
            }
            if(vv.size()){
                  for(ll i = vv[0] - 1; i >= max(0ll, vv[0]-K); i--)
                        a[i] = 1;
                  for(ll i = vv[vv.size() - 1] + 1; i <= min(n - 1, vv[vv.size() - 1] + K); i++)
                        a[i] = 1;
            }
            f(i,0,n) cout << a[i];
            nl;
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      //*
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif/**/

      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}

