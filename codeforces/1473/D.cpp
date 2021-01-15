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
ll const inf = 1e9;
ll const maxn = 1e5+1;
class The{
public:
      ll up, down;
};

void solve()
{
      ll n,m; cin >> n >> m;
      string s; cin >> s;

      ll premax[n+1]={0}, premin[n+1]={0};
      ll postmax[n+2]={0}, postmin[n+2]={0};
      ll x = 0;
      ll xVal[n+1]={0}, xVal2[n+2]={0};
      for(ll i = 0; i<n; i++){
            x += (s[i]=='+'?1:-1);
            xVal[i+1]=x;
            premax[i+1]=max(premax[i],x);
            premin[i+1]=min(premin[i],x);
      }
      // cout << x << endl;
      ll X = x;
      x=0;
      for(ll i = n-1; i>=0;i--){
            x += (s[i]=='+'?-1:1);
            postmax[i]=max(postmax[i+1],x);
            postmin[i]=min(postmin[i+1],x);
            xVal2[i]=x;
      }
      // postmax[n+1]=xVal2[n+1]=X;
      while(m--){
            ll u,v; cin>>u>>v;
            //1 -> u-1
            ll prehigh = premax[u-1];
            ll prelow = premin[u-1];
            // v+1 -> n
            ll posthigh = xVal[u-1] + ( postmax[v]- xVal2[v]);
            ll postlow = xVal[u-1] + ( postmin[v] - xVal2[v]);
            // cout << prehigh << " " << prelow << " || " << posthigh << " " << postlow << endl;
            // cout << postmax[v+1] << " ___  " << postmin[v+1] << " ___ " << xVal2[v+1] << endl; 

            cout << abs( max( prehigh,posthigh ) - min(prelow, postlow) ) + 1 << endl;
      }

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