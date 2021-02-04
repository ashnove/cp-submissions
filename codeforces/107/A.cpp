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

vector<pair<ll,ll>> adj[maxn];


void solve()
{
      ll n,m; cin >> n >> m;
      ll indegree[n+1]={0}, outdegree[n+1]={0};
      for(ll i = 0; i < m; i++){
            ll u,v,w; cin>>u>>v>>w;
            adj[u].pb({v,w});
            indegree[v]++;
            outdegree[u]++;
      }

      vector<ll> ans[(ll)1e5];
      vector<vector<ll>> vv(n+1, vector<ll>(n+1, inf)); 
      for(ll i = 1; i <= n; i++){
            if(indegree[i])continue;
            priority_queue< pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
            pq.push({inf, i});

            while(!pq.empty()){
                  ll v = pq.top().second;
                  ll d = pq.top().first;
                  pq.pop();
                  if(d > vv[i][v])continue;
                  for(auto to : adj[v]){
                        if( min(d,to.second) < vv[i][to.first] ){
                              vv[i][to.first]=min(d,to.second);
                              pq.push({min(d,to.second), to.first});
                        }
                  }
            }

      }
      ll it = 0;
      for(ll i = 1; i <= n; i++){
            if(indegree[i])continue;
            for(ll j = 1; j <= n; j++){
                  if(outdegree[j] || vv[i][j]>=inf)continue;
                  ans[it].pb(i);
                  ans[it].pb(j);
                  ans[it++].pb(vv[i][j]);
            }
      }
      cout << it << endl;
      for(ll i = 0; i < it ; i++)
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
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