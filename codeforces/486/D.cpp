/*@author : ashnove*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl;
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b){ 
    if(a.first < b.first ) return 1;
    if( a.first==b.first && a.S != b.second ) return 1;
    return 0;
}
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 5e3+1;

ll val[maxn], dp[maxn],d,n;
vector<ll> adj[maxn];
void dfs(ll from , ll start, ll par)
{
      dp[from] = 1;
      for(auto to : adj[from]){
                        // cout << 1 << endl;
            if(to != par){
                  if(val[to]==val[start] && start > to) continue;
                 
                  if( val[to] >=val[start] && val[to]<=val[start]+d ){
                        dfs(to, start, from);
                        dp[from] = (dp[from] + (dp[from]*dp[to])%mod)%mod;
                  }
            }
      }
}
void solve()
{
      cin >> d >> n;

      for(ll i = 0; i < n; i++ )
            cin >> val[i+1];

      for(ll i = 0; i<n-1; i++ ){
            ll u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
      }
      ll ans = 0;
      for(ll i = 1; i<=n; i++){
            fill(dp, dp+n+1, 0);
            dfs(i,i,-1);
            ans = (ans + dp[i])%mod;
      }
      cout << ans << endl;
}     

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
            ll t;
            /**/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      return 0;
}     