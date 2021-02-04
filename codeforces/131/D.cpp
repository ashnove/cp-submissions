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
ll const maxn = 3e3+1;

vector<ll> adj[maxn];
vector<ll> vis(maxn);
vector<ll> parent(maxn);
vector<ll> depth(maxn, inf);
ll start,last;
void dfs(ll from, ll par=-1){

      vis[from] = 1;
      for(auto to : adj[from]){
            if(!vis[to]){
                  parent[to]=from;
                  dfs(to, from);
            }
            else if(to!=par){
                  start = from, last = to;
            }
      }
}
void solve()
{
      ll n; cin >> n;
      for(ll i = 0; i < n; i++){
            ll u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
      }     
      dfs(1);

      priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
      pq.push({0ll,last});
      depth[last]=0;
      while(last^start){
            last=parent[last];
            depth[last]=0;
            pq.push({0ll,last});
      }
      while(!pq.empty()){
            ll node = pq.top().second;
            ll w = pq.top().first;
            pq.pop();
            if(w > depth[node])continue;
            for(auto ch : adj[node]){
                  if( w + 1 < depth[ch] ){
                        depth[ch] = w + 1;
                        pq.push({depth[ch], ch});
                  }
            }
      }
      
      for(ll i = 1; i <= n; i++)
            cout << depth[i] << " ";
      nl;

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