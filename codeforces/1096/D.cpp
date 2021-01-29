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
// ll const mod =  63018038201;4
// 1125899906842597
ll const mod = 1e9+7;
ll const inf = 1e15;
ll const maxn = 5e5+1;

void solve()
{
      ll n; cin >> n;
      string s; cin >> s;

      ll a[n+1];
      for(ll i = 0; i < n; i++)
            cin >> a[i+1];

      ll dp[n+1][5];
      for(ll i = 0; i <= n; i++)
            for(ll j = 0; j <= 4; j++)
                  dp[i][j] = inf;

      for(ll i = 1; i <= 4; i++){
            dp[0][i] = 0;
      }
      string t = "hard";
      for(ll i = 1; i<=n; i++){
            for(ll j = 1; j <= 5; j++){
                  if( s[i-1] == t[j-1] )
                        dp[i][j] = min( a[i] + dp[i-1][j], dp[i-1][j-1] );
                  else
                        dp[i][j] = dp[i-1][j];
            }
      }     

      ll ans = inf;
      for(ll i = 1; i<=5; i++)
            ans = min(dp[n][i], ans);
      cout << ans << endl;
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
      return 0;
}      