/*
* author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl;
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mod 100000007
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
//me
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+5;
ll sumA, sumB;
vector<ll> adj[maxn];
ll vis[maxn], a[maxn], b[maxn];

void dfs(ll x){
      vis[x]=1;
      sumA += a[x];
      sumB += b[x];
      for(auto ch : adj[x]){
            if(!vis[ch])
                  dfs(ch);
      }
}

void solve()
{     
      
      ll n,m; cin >> n >> m;
      bool ok = 1;
      f(i,1,n+1){
            cin >> a[i];        
      }
      f(i,1,n+1){
             cin >> b[i];         
      }
      f(i,0,m){
            ll u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
      }

      ll cnt = 0;
      for(ll i = 1; i<=n; i++){
            sumA = 0, sumB = 0;
            if(vis[i]==0){
                  dfs(i), cnt++;
                  if(sumA!=sumB)ok=0;
            }
      }

      if( ok)
            cout << "Yes";
      else
            cout << "No";

}
    
int main() {
Knucklehead 
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