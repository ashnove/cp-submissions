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
bool comp( const array<ll,3> &a, const array<ll,3> &b ){
      if( a[0] < b[0] )
            return 1;
      if( a[0] == b[0] && a[1] > b[1] ) 
            return 1;
      return 0;
}            
// ll const mod =  63018038201;4
// 1125899906842597
ll const mod = 1e9+7;
ll const inf = 1e15;
ll const maxn = 1e5+1;
vector< pair<ll,ll>> adj[maxn];
ll vis[maxn], b[maxn];
bool ok = 1;
bool dfs(ll from){
      vis[from] = 1;
      for(auto to : adj[from]){
            // to.F , to.S
            if(!vis[to.F]){
                  if(to.S)b[to.F]=b[from];
                  else b[to.F] = b[from]^1; 
                  if(!dfs(to.F)) return 0;
            }else{
                  if(to.S && b[from]!=b[to.F])return 0;
                  if(!to.S && b[from]==b[to.F])return 0;
            }
      }
      return 1;
}
void solve()
{
      ll n,m; cin >> n >> m;
      ll col[maxn];
      bool g = 0;
      for(ll i = 1; i <= n;i++){
            cin >> col[i];
            if(col[i]==0) g = 1;
      }

      vector<ll> edges[maxn]; 
      bool f = 0; 
      for(ll i = 0; i < m ; i++){
            ll x; cin >> x;
            if(x>0)f=1;
            for(ll j = 0; j < x; j++){
                  ll r; cin >> r;
                  edges[r].pb(i+1);
            }
      }     
      if(!f){
            cout << (g?"NO\n":"YES\n");
            return;
      }
      for(ll i = 1; i <= n; i++){
            ll u = edges[i][0], v = edges[i][1];
            adj[u].pb({v,col[i]});
            adj[v].pb({u,col[i]});
      }
      ok = 1;
      f(i,0,m){
            if(!vis[i+1])
            ok &= dfs(i+1);
      }
      cout << (ok?"YES\n":"NO\n");
}     

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
            ll t;
            /**/t=1;
            /*/cin >> t;/**/
            f(testcases,0,t){
               // cout << "Case " <<testcases+1<<": ";
               solve();
            } 
      return 0;
}      