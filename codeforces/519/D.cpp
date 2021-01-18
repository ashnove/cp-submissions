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
      ll val[27];
      for(ll i = 0; i<26; i++)
            cin >> val[i+1];

      vector<ll> every_alph[26];
      string s; cin >> s;
      ll n = s.size();

      for(ll i = 0; i<n; i++ )
            every_alph[s[i]-97].pb(i+1);

      ll rangeSum[n+1]={0};
      for(ll i = 1; i<=n; i++)
            rangeSum[i] = rangeSum[i-1] + val[s[i-1]-96];
      ll ans = 0;

      for(ll i = 0; i < 26; i++){

            map<ll,ll> cnt;
            ll cur = 0;
            for(ll j = 1; j < every_alph[i].size(); j++){
                  ++cnt[ rangeSum[every_alph[i][j-1]]];
                  ans += cnt[rangeSum[every_alph[i][j]-1]];
            }
      }

      cout << ans << endl;
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