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
ll const maxn = 1e5+1;

struct The{
      ll cnt, fence, pos;
};
char max(char a, char b){
      if(a>b)
            return a;
      return b;
}
ll sum(ll a, ll b){

      return (b*(b+1)/2) - (a*(a-1)/2 + mod)%mod;

}     
void solve()
{      
      
      ll n,k; cin >> n >> k;

      ll L = inf,R=0, ans = 0;
      while(k<=n+1){
            L = sum(0,k-1);
            R = sum(n-k+1, n);
            ans = (ans + (R-L+1+mod)%mod)%mod;
            k++;
      }
      cout << ans << endl;

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