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

void solve()
{
      
      ll n; cin >> n;

      vector<ll> p[n+2]; 
      ll vis[n+2]={0};   
      ll ans = 0;
      for(ll i = 2; i<=n+1;i++ ){
            // cout << p[i].size() << " ";
            if(p[i].size()==0)
                  for(ll j = 2*i; j<=n+1; j+=i){
                        p[j].pb(i);
                        ans = max(ans, (ll)p[j].size());
                  }
      }
      ll col[n+2]={1};

      for(ll i = n+1; i>=2; i-- ){
            // ll cur = ans+1;
            if(vis[i]==0){
                  col[i]=1;
                  vis[i]=1;
                  for(ll e : p[i]){
                        // cout << i << " " << e << " ";
                        if(vis[e]==0){
                              col[e]=2;
                              vis[e]=1;
                        }
                  }

            }
      }
      cout << (n<3?1:2) << endl;
      for(ll i = 2; i<=n+1; i++)
            cout << col[i] << " ";
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