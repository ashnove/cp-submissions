/*
      @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define lld long double
#define F first
#define S second
#define Th third
#define endl "\n"
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
ll const maxn = 2e5 + 1;

ll score(string s, ll x, ll y) {
      ll n = s.size();

      ll res = 0;
      for (ll i = 1; i < n; i++) {
            if (s[i] == 'J' && s[i - 1] == 'C') res += x;
            else if (s[i] == 'C' && s[i - 1] == 'J') res += y;
      }
      return res;
}

void solve()
{
      ll t = 1;
      cin >> t;
      for (ll tt = 1; tt <= t; tt++) {

            ll n; cin >> n;

            ll even = 0, odd = 1;    
            while(n%2==0)
                  even++, n/=2;
            // cout << odd << " " << even << endl;
            if(1 == even )
                  cout << "Same\n";
            else if(even)
                  cout << "Even\n";
            else cout << "Odd\n";

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