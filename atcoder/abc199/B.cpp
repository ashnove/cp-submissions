/*
      @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define F first
#define S second
#define Th third
// #define endl "\n"
#define nl cout << endl;
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(x) cerr << #x << " is " << x << endl;
#define ar vector<ll>
#define mat vector<vector<ll>>
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}
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

ll const mod = 1e9 + 7;
ll const inf = 1e18;
ll const maxn = 5e5 + 1;



void solve()
{
      ll t = 1;
      // cin >> t;

      for (ll tt = 1; tt <= t; tt++) {

            ll n; cin >> n;
            ll a[n]; f(i,0,n) cin >> a[i];
            ll b[n]; f(i,0,n) cin >> b[i];

            ll p[1001] = {0};

            ll ans = 0;
            ll aa = 0, bb = inf;
            f(i,0,n){

                  aa= max(aa, a[i]);
                  bb= min(bb, b[i]);
                  p[a[i]]++;
                  if(b[i] + 1 < 1001)
                        p[b[i] + 1]--;
            }
            for(ll i = 1; i< 1001; i++){
                  p[i] += p[i-1];
                  if(p[i] > 0)ans++;
            }

            cout << (bb - aa + 1 < 0 ? 0 : bb - aa + 1) << endl;

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