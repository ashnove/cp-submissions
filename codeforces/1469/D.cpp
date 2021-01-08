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
ll const maxn = 5e5+1;


void solve()
{      
      ll n; cin >> n;

      vector<ll> ans;
      ll last = n;
      for(ll i = n-1; i>=3; i--){

            if( i*i <= n ){
                  ans.pb(last);
                  ans.pb(i);
                  n = (n+i-1)/i;
            }
            ans.pb(i);
            ans.pb(last);
      }

      while(n>1){
            n= (n+1)/2;
            ans.pb(last), ans.pb(2);
      }
      cout << ans.size()/2 << endl;
      for(ll i = 0; i<ans.size(); i+=2)
            cout << ans[i] << " " << ans[i+1] << endl;


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
      return 0;
}     