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
#define endl "\n"
#define nl cout<<endl;
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define what_is(x) cerr << #x << " is " << x << endl;
#define mat vector<vector<ll>>
mat cn(ll n, ll m) {return vector< vector<ll> >(n, vector<ll>(m));}
bool comp1(char &s1, char &s2) {return s1 > s2;}
bool comp2(const pair<ll, pair<ll, ll>> &a,  const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first ) return 1;
      if ( a.first == b.first && a.S.S > b.S.S ) return 1;
      return 0;
}
class Pair { public: ll first, second;};
bool comp3(const Pair &a, const Pair &b) {
      if (a.F > b.F) return 1;
      return 0;
}
class Trips { public: ll first, second, third;};      
bool comp4(const Trips &a, const Trips &b) {
      if (a.Th > b.Th) return 1;
      return 0;
}

ll const mod = 1e9 + 7;
ll const inf = 1e18;
ll const maxn = 2e5 + 1;

vector<ll> adj[maxn];
ll vis[maxn];
ll ed,vv;
void dfs(ll x){
      vis[x] = 1;
      vv++;
      for(auto ch : adj[x]){
            ed++;
            if(!vis[ch]){
                  dfs(ch);
            }
      }
}
void solve()
{

      ll n,m; cin >> n >> m;
      for(ll i = 0; i < m; i++){
            ll u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
      }
      bool ok = 1;
      for(ll i = 1; i <= n; i++){
            if(!vis[i]){
                  ed = 0, vv = 0;
                  dfs(i);
                  if(ed!=vv*(vv-1))ok=0;
            }
      }
      cout << (ok?"YES\n":"NO\n");
}


int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
//*
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
      /**/
      ll tt = 1;
      // cin >> tt;
      f(testcases, 0, tt) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}