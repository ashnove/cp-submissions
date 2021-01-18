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
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 5e3+1;


void solve()
{
      ll n,k,p; cin >> n >> k >> p;

      queue<ll> odd, even;
      ll a[n];
      for(ll i = 0; i< n; i++){
            cin >> a[i];
            if(a[i]&1) odd.push(a[i]); else even.push(a[i]);
      }
      ll rem = k-p;
      if( odd.size() < rem || (odd.size()-rem)&1 ){
            cout << "NO\n";
            return;
      }
      vector<ll> ans[k];

      for(ll i = 0; i<rem; i++){
            ans[i].pb(odd.front());
            odd.pop();
      }

      ll it = rem;
      while(it < k && !odd.empty()){
            ans[it].pb(odd.front());
            odd.pop();
            ans[it++].pb(odd.front());
            odd.pop();
      }

      while(it < k && !even.empty()){
            ans[it++].pb(even.front());
            even.pop();
      }
      while(!even.empty()){
            ans[k-1].pb(even.front());
            even.pop();
      }
      while(!odd.empty()){
            ans[k-1].pb(odd.front());
            odd.pop();
      }
      bool ok = 1;
      for(ll i = 0; i < k; i++)
            if(ans[i].size()==0)ok=0;
      if(!ok){
            cout << "NO\n"; return;
      }
      cout << "YES\n";
      for(ll i = 0; i < k; i++){
            cout << ans[i].size() << " ";
            for(auto e : ans[i])
                  cout << e << " ";
            nl;
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
            /**/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      return 0;
}     