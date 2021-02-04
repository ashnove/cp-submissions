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
ll const dr[] = {-1,-1,-1,0,1,1,1,0};
ll const dc[] = {-1,0,1,1,1,0,-1,-1};
void solve()
{
      ll x0,y0,x1,y1;
      cin>>x0>>y0>>x1>>y1;
      ll n; cin >> n;
      ll it = 0;
      map< pair<ll,ll>, ll> depth;
      map<pair<ll,ll>,ll> used, vis;
      map< ll, vector<ll>> mp;
      vector<ll> adj[maxn];
      for(ll i = 0; i < n; i++ ){
            ll r,a,b; cin >> r >> a >> b;

            for(ll j = a; j <= b; j++){
                  mp[r].pb(j);
                  used[{r,j}] = 1;
            }
      }
      queue< pair<ll,ll> > q;
      q.push({x0, y0});
      vis[{x0, y0}]=0;
      while(!q.empty()){
            pair<ll,ll> cur = q.front();
            q.pop();
            for(ll i = 0; i < 8; i++){
                  ll r = cur.F + dr[i], c = cur.S + dc[i];
                  if( used[{r,c}] && !vis[{r,c}] ){
                        vis[{r,c}]=1;
                        depth[{r,c}] = depth[cur] + 1;
                        q.push({r,c});
                  }
            }
      }
      cout << (depth[{x1, y1}]?depth[{x1,y1}]:-1) << endl;
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