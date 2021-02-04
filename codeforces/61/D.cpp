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
ll const maxn = 3e5+1;

vector<pair<ll,ll>> adj[maxn];
ll vis[maxn];
ll dfs(ll x){
      vis[x]=1;
      ll res = 0;
      for(pair<ll,ll> to : adj[x]){
            if(!vis[to.F]){
                  res = max(res, to.S+dfs(to.F));
            }
      }
      return res;
}

void solve()
{
      ll n,m; cin >> n; m= n-1;
      ll sum = 0;
      for(ll i = 0; i < m; i++){
            ll u,v,w; cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            sum+=w+w;
      }
      ll val = dfs(1);
      cout << sum-val << endl;
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