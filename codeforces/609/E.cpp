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
// ll const mod =  63018038201;4
// 1125899906842597
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 5e5+1;
vector< pair<ll,ll> > adj[maxn];
ll vis[maxn], cost[maxn], ancestor[maxn][21], maxWeight[maxn][20], depth[maxn];
ll parent[maxn], Rank[maxn];
ll find(ll x){
      if(parent[x] < 0)
            return x;
      return parent[x] = find(parent[x]);
}

void merge(ll a, ll b){
      a = find(a), b=find(b);
      if(a==b)return;
      if( Rank[a] > Rank[b] ){
            Rank[a]+=Rank[b];
            parent[b]=a;
      }else{
            Rank[b]+=Rank[a];
            parent[a]=b;
      }
}


void dfs(ll x, ll d=0,ll par=-1)
{
      vis[x] = 1;
      ancestor[x][0] = par;
      depth[x] = d;
      for(pair<ll,ll> ch : adj[x])
      {
            if(vis[ch.first]==0){
                  maxWeight[ch.first][0] = ch.S;
                  dfs(ch.first,d+1, x);
            }
      }
}
 
ll calc(ll a, ll jump){
 
      ll res = 0;
      while(jump>0){
 
            ll i = log2(jump);
            res = max(res, maxWeight[a][i]);
            a = ancestor[a][i];
            jump -= (1<<i);
 
      }
 
      return res;
}
 
void lookup_table()
{
      for(ll j = 1; j<=20; j++ ){
            for(ll i = 1; i<maxn; i++){
                  if( ancestor[i][j-1]!= -1 )
                  {
                        maxWeight[i][j] = max({ maxWeight[i][j], maxWeight[i][j-1], maxWeight[ancestor[i][j-1]][j-1] });
                        ancestor[i][j] = ancestor[ ancestor[i][j-1] ][j-1];
                  }
            }
      }
}
ll lca(ll a, ll b)
{
      if( depth[a] > depth[b] ) swap(a,b);
      ll jumps = depth[b]-depth[a];
 
      while(jumps>0){
            ll i = log2(jumps);
            b = ancestor[b][i];
            jumps-=(1<<i);
      }
      if(a==b) return a;
 
      for(ll i = 20; i >= 0; i--){
            if( ancestor[a][i]!=-1 && ancestor[a][i]!=ancestor[b][i] )
                  a = ancestor[a][i], b = ancestor[b][i];
      }
 
      return ancestor[a][0];
}
void solve()
{
      // n = 10^5;
      fill(parent, parent+maxn, -1);
      fill(Rank, Rank+maxn, 1);
      memset(ancestor, -1, sizeof ancestor);
      memset( maxWeight , 0, sizeof maxWeight);
      ll n,m; cin >> n >> m;

      vector< pair<ll, pair<ll,ll>>> vv, vv2;
      vector<pair<ll,ll>> nodes;
      for(ll i = 0; i < m; i++){
            ll u,v,w;  cin >> u >> v >> w;
            vv.pb({w, {u,v}});
            vv2.pb({w, {u,v}});
            nodes.pb({u,v});
      }
      sort(vv.begin(), vv.end());

      ll sum = 0;
      map< pair<ll,ll>, ll > treeset;
      for(auto e : vv){
            ll a = e.S.F, b = e.S.S;
            if( find(a)!=find(b) ){
                  merge(a,b);
                  sum += e.F;
                  adj[a].pb({b,e.F});
                  adj[b].pb({a,e.F});
            }
      }
      dfs(1);
      lookup_table();

      // ll minW[n+1];
      // fill(minW, minW+n+1, inf);
      // for(auto e : vv){
      //       ll a = e.S.F, b = e.S.S, cw=e.F;
      //       if(treeset[a]&&!treeset[b])
      //             minW[b]=min(minW[b], cw);
      //       if(treeset[b]&&!treeset[a])
      //             minW[a]=min(minW[a], cw);
      // }
      
      
      for(auto e : vv2){
            ll a = e.S.F, b = e.S.S, cw=e.F;
            ll X = lca(a , b);
            ll val = max(calc( a, depth[a]-depth[X] ), calc(b, depth[b]-depth[X]));
            cout << sum - val + cw << endl;
      }


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
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      return 0;
}     