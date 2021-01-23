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
bool sortmahstyle(const pair<ll, pair<ll,ll>> &a,  const pair<ll, pair<ll,ll>> &b){ 
    if(a.first > b.first ) return 1;
    if( a.first==b.first && a.S.S > b.S.S ) return 1;
    return 0;
}
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+1;
class The{
public:
      ll up, down;
};
ll parent[maxn], Rank[maxn];


ll find(ll x){
      if(parent[x] < 0)
            return x;
      return parent[x] = find(parent[x]);
}
void merge(ll a, ll  b){
      a = find(a), b = find(b);
      if(a==b) return;
      if(Rank[a] > Rank[b]){
            Rank[a] += Rank[b];
            parent[b]=a;
      }
      else{
            Rank[b] += Rank[a];
            parent[a]=b;
      }
}
void solve()
{
      ll n,m,k; cin >> n >> m >> k;
      fill(parent, parent + n + 1, -1);
      fill(Rank, Rank + n + 1, 1);     
      vector< pair<ll,pair<ll,ll>> > all;
      for(ll i = 0; i < m; i++ ){
            ll u,v,w; cin >> u >> v >> w;
            all.pb({ w, { u, v } });
      }
      sort(all.begin(), all.end());
      ll ans = 0, inc = inf;
      for(auto e : all){

            if( find(e.S.F)!=find(e.S.S) ){
                  ans += max(0ll, e.F - k);                  
                  merge(e.S.F, e.S.S);
            }
            inc = min(inc, abs(e.F-k));
      }
      cout << (ans==0?inc:ans) << endl;

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
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     