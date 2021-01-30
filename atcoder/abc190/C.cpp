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
void solve()
{
      ll n,m; cin >> n >> m;

      vector< pair<ll,ll>> vv, ch;

      f(i,0,m){
            ll u,v; cin >> u >> v;
            vv.pb({u,v});
      }
      ll k; cin >> k;
      f(i,0,k){
            ll u,v; cin >> u >> v;
            ch.pb({u,v});
      }
      ll fok = 0;
      for(ll i = 0; i < (1ll<<k); i++){

            ll a[n+1]={0};
            for(ll j = 0; j<k; j++){

                  if( i & (1<<j) )
                        a[ch[j].F]++;
                  else  a[ch[j].S]++;

            }
            bool ok = 1;
            ll cur = 0;
            for(ll i = 0; i<m; i++){
                  if( a[vv[i].F] &&  a[vv[i].S])
                        cur++;
            }
            fok = max(fok,cur);
      }
      cout << fok;
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