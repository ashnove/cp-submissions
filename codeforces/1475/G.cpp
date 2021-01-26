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
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
//me19U10584
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+1;
ll f[maxn];
void fact(){
      f[0]=1;
      for(ll i = 1; i < maxn; i++)
            f[i] = (f[i-1]*i)%mod;
}
ll powmod(ll a, ll b){
      ll res =1 ;
      while(b){
            if(b&1)res = res*a%mod;
            a = a*a%mod;
            b/=2;
      }
      return res;
}
ll inv(ll x){
      return powmod(x, mod-2);
}
ll choose(ll n, ll r){
      return ((f[n]*inv(f[n-r])%mod) *inv(f[r]) )%mod;
}
void solve()
{            
      ll n; cin >> n;
      ll a[n], cnt[maxn]={0};
      for(ll i = 0; i < n; i++ )
            cin >> a[i], cnt[a[i]]++;

      ll dp[maxn]={0};
      for(ll i = maxn-1; i >= 1; i--){
            for(ll j = i; j<maxn; j+=i)
                  dp[i] = max(dp[i], dp[j]+cnt[i]);
      }
      cout << n-dp[1] << endl;
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
            fact();
            ll t;
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
                  // cout << "Case #" <<testcases+1<<": ";
                  solve();
            }
 
 
    return 0;
}     