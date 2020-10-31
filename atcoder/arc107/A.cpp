/*
* @author : ashnove
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
ll const mod = 998244353;
ll const inf = 1e18;
ll const maxn = 3e5+1;
ll modpow(ll a, ll b){
      ll res = 1;
      while(b){
            if(b&1)
            res = (res*a)%mod;
            a = (a*a)%mod;
            b/=2;
      }
      return res;
}
ll inv(ll x){
      return modpow(x, mod -2);
}

void solve()
{      
      
      ll a, b, c; cin >> a >> b >> c;
      ll X = ((a%mod*(a+1)%mod)%mod * inv(2))%mod;
      ll Y = ((b%mod*(b+1)%mod)%mod * inv(2))%mod;
      ll Z = ((c%mod*(c+1)%mod)%mod * inv(2))%mod;
      cout << ( (X*Y)%mod *Z )%mod << endl;
            
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