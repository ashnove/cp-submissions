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
ll const maxn = 2e7+5;

ll f[maxn];

void factorial()
{
      f[0] = 1;
      for(ll i = 1; i<=maxn; i++)
            f[i] = (f[i-1]*i) %mod;
}
ll powmod(ll a, ll b)
{
      ll res = 1;
      while(b){
            if(b&1) res = (res * a) % mod;
            a = (a*a)%mod;
            b/=2;
      }
      return res;
}
ll inv(ll x)
{
      return powmod(x, mod - 2);
}
ll choose(ll n, ll r)
{
      return ( (f[n]*inv(f[n-r]))%mod * inv(f[r]) ) % mod;
}

ll op(ll a, ll b, ll c, ll d)
{
      return abs( a*d - b*c )%mod;
}
void solve()
{     
      factorial();
      ll x, y; cin >> x >> y;

      if((x+y)%3!=0 ||  y > 2 * x || x > 2 * y){
            cout << 0 << endl;
            return;
      }
      ll D = op(1, 2, 2, 1);
      ll A = op(x, 2, y, 1);
      ll B = op(1, x, 2, y);
      A /= D, B /= D;
      
      if( (A+B)>=0 &&  A >= 0)  
            cout << choose(A+B, A) << endl;
      else
            cout << 0 << endl;
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