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
ll const inf = 1e18;
ll const maxn = 5e3+1;


ll modpow(ll a, ll b)
{
      ll res = 1;
      while(b){
            if( b&1 )res = (res * a) % mod;
            a = a*a%mod;
            b/=2; 
      }
      return res;
}
ll inv(ll x){
      return modpow(x, mod - 2 );
}
void solve()
{
      string s; cin >> s;

      string val; cin >> val;
      ll k; cin >> k;
      ll n = s.size();
      ll rangeVal[n+1]={0};
      for(ll i = 1; i <= n; i++)
            rangeVal[i] = rangeVal[i-1] + (val[s[i-1]-'a']=='1'?0:1);

      ll powVal[n], invVal[n];
      for(ll i = 0; i < n; i++){
            powVal[i] = modpow(31, i);
            invVal[i] = inv(powVal[i]);
      }

      ll sHash[n+1][n+1];
      memset(sHash,0,sizeof sHash);
      ll ans = 0;
      map<ll,ll> visited;
      for(ll i = 1; i <= n; i++){
            for(ll j = i; j <= n; j++){
                  sHash[i][j] = (sHash[i][j-1]*29ll + s[j-1]);
                  // ll curHash = ((sHash[j] - sHash[i-1] + mod) %mod * invVal[i-1] )%mod;
                  if( visited[sHash[i][j]]==0 ){
                        visited[sHash[i][j]]=1;
                        if( rangeVal[j]-rangeVal[i-1] <= k ){ 
                              ans++;
                        }
                  }


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