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
ll const maxn = 1e5 + 1;

vector<ll> adj[maxn];
ll vis[maxn];
ll col[maxn];
ll used[maxn];
ll cnt[maxn];
vector<ll> ans;
void dfs(ll x, ll used[]) {
      vis[x] = 1;
      for (ll ch : adj[x]) {
            if (!vis[ch]) {

                  ll putt = col[ch];
                  if (used[putt] == 0)
                        ans.pb(ch);
                  used[putt]++;
                  dfs(ch, used);

                  used[putt]--;
            }
      }
}
void solve()
{
      ll t = 1;
      // cin >> t;
      for (ll tt = 1; tt <= t; tt++) {

            string a, b, c; cin >> a >> b >> c;

            set<char> s;
            for (char e : a) s.insert(e);
            for (char e : b) s.insert(e);
            for (char e : c) s.insert(e);

            if (s.size() > 10) {
                  cout << "UNSOLVABLE\n";
                  continue;
            }
            vector<char> chr;
            vector<ll> dig;
            ll it = 0;
            map<char, ll> pos;
            ll pp = 0;
            for (auto e : s) {
                  chr.pb(e);
                  pos[e] = pp++;
            }
            ll m = 10;
            while (m--) {
                  dig.pb(it++);
            }
            ll n = chr.size();
            // for(auto e: dig){
            //       cout <<e << " ";
            // }
            // nl

            do {
                  map<char, ll> d;
                  for (ll i = 0; i < n; i++) {
                        d[chr[i]] = dig[i];
                  }

                  ll x = 0, y = 0, z = 0;
                  bool ok = 1, f = 1;
                  for (char e : a) {
                        if (f && d[e] == 0)ok = 0;
                        f = 0;
                        x = x * 10 + d[e];
                  } f = 1;
                  for (char e : b) {
                        if (f && d[e] == 0)ok = 0;
                        f = 0;
                        y = y * 10 + d[e];
                  }
                  f = 1;
                  for (char e : c) {
                        if (f && d[e] == 0)ok = 0;
                        f = 0;
                        z = z * 10 + d[e];
                  }

                  if (ok && x + y == z) {
                        cout << x << endl;
                        cout << y << endl;
                        cout << z << endl;
                        goto outer;
                  }




            } while (next_permutation(dig.begin(), dig.end()));

            cout << "UNSOLVABLE\n";

outer:
            ;
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