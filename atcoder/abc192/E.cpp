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
#define what_is(x) cerr << #x << " is " << x << endl;
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll, pair<ll,ll>> &a,  const pair<ll, pair<ll,ll>> &b){ 
    if(a.first > b.first ) return 1;
    if( a.first==b.first && a.S.S > b.S.S ) return 1;
    return 0;
}

ll const mod = 1e9+7;
ll const inf = 1e17;
ll const maxn = 2e5+1;

vector<pair<ll, pair<ll,ll> >> adj[maxn];
vector<ll> dis(maxn, inf);
void solve()
{   
      ll n,m; cin >> n >> m;
      ll x,y; cin >> x >> y;
      while(m--){
            ll u,v,w,k; cin >> u >> v >> w >> k;
            adj[u].pb({v, {w,k} });
            adj[v].pb({u, {w,k} });
      }
 
      priority_queue< pair<ll,ll>, vector<pair<ll,ll >>, greater<pair<ll,ll >> > q;
      q.push({0,x});
      dis[x]=0;
      while(!q.empty()){
 
            ll curNode = q.top().S;
            ll curWgt = q.top().F;
            q.pop();
            if(curWgt>dis[curNode]) continue;
            for(auto ch : adj[curNode]){
 
                  if( curNode==x )
                  {     
                        if (curWgt + ch.S.F < dis[ch.F] ){
                              dis[ch.F] = curWgt + ch.S.F ;
                              q.push({dis[ch.F], ch.F});
                        } 
                  }
                  else{

                        ll mulOf = ch.S.S;
                        ll extra = 0;
                        if(curWgt <= mulOf)
                              extra = mulOf - curWgt;
                        else{
                              ll p = (curWgt + mulOf - 1)/mulOf;
                              extra = mulOf*p - curWgt;
                        }
                        if (curWgt + extra + ch.S.F < dis[ch.F] ){
                              dis[ch.F] = curWgt + ch.S.F +extra;
                              q.push({dis[ch.F], ch.F});
                        } 
                  }  
 
            }
 
      }
 
      // f(i,1,n+1){
      //       cout << dis[i] << " ";
      // }
      if(dis[y] >= inf) cout << -1 << endl;
      else cout << dis[y] << endl;
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
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}          