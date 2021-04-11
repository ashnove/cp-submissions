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
void dfs(ll x, ll used[]){
      vis[x] = 1;
      for(ll ch : adj[x]){
            if(!vis[ch]){

                  ll putt = col[ch];
                  if(used[putt]==0)
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
            ll n; cin >> n;

            f(i,1,n+1)
                  cin >> col[i];
            for(ll i = 0; i < n-1; i++){
                  ll u,v; cin >> u >> v;
                  adj[u].pb(v);
                  adj[v].pb(u);
            }
            set<ll> s;
            used[col[1]]++;
            ans.pb(1);
            dfs(1, used);
            sort(ans.begin(), ans.end());
            for(auto e : ans){
                  cout << e << endl;
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