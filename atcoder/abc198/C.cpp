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
ll const maxn = 1e7 + 1;

bool pallin(string s){

      ll n = s.size();
      ll i = 0, j = n-1;
      n/=2;
      for(ll  i = 0; i < n; i++){
            if(s[i]!=s[j])
                  return 0;
            j--;
      }
      return 1;
}
void solve()
{
      ll t = 1;
      // cin >> t;
      for (ll tt = 1; tt <= t; tt++) {
            ll r, x,y; cin >> r >> x >> y;

            lld dis = (lld)(x*x + y*y);
            dis = (lld)sqrt(dis);

            // cout << dis << endl;
            if(floor(dis) == ceil(dis)){
                  ll p = floor(dis);
                  if(p % r == 0)
                        cout << p/r;
                  else 
                        {
                              cout << max(0ll,(p- 2*r + r - 1)/r) + 2;
                        }
            }else{
                  // ll p = floor(dis);
                  if(dis >= 2*r)
                        dis-=2*r; else dis = 0;
                  ll p = ceil(dis/r);
                  cout << p + 2;
            }
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