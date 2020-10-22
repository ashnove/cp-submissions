/*
* author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl;
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mod 100000007
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
//me
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+5;

ll logb(ll a, ll b){

      return log2(a)/log2(b);
}
ll powpow(ll a, ll b){
      ll res = 1;
      while(b){

            if(b&1) res *= a;
            a*=a;
            b/=2;
      }
      return res;
}

void solve()
{     
      ll n; cin >>n ;
 
      ll a = logb(n,9);
      ll b = logb(n,6);
      ll dp[n+1];
      f(i,0,n+1) dp[i]=i;

      for(ll i = 1; i <= n; i++ ){
      
            for(ll j = 1; j<=a; j++){
                  ll cur = powpow(9,j);
                  if(i-cur>=0)
                        dp[i] = min(dp[i], 1 + dp[i-cur]);
            }
            for(ll j = 1; j<=b; j++){
                  ll cur = powpow(6,j);
                  if(i-cur>=0)
                        dp[i] = min(dp[i], 1 + dp[i-cur]);
            }
      }
      cout << dp[n] << endl;
}
    
int main() {
Knucklehead 
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