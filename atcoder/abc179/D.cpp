/*
 * Author: ashnove
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

#define mat vector<vector<ll>>
mat cn(ll n, ll m)
     {return vector< vector<ll> >(n, vector<ll>(m));}

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
ll const inf = 1e18+1;
ll const maxn = 2e1+2;
ll powmod(ll a, ll b)
{
     ll res = 1;
     while(b){
          if(b&1) res = ( res * a) % mod;
          a = (a*a) % mod;
          b/=2;
     }
     return res;
}
void solve()
{
     ll n,k; cin >> n >> k;

     array<ll,2> r[k];
     f(i,0,k)
          cin >> r[i][0] >> r[i][1];

     sort(r,r+k);
     ll dp[n+1]={0};
     dp[1]=1;
     ll pref[n+1]={0};
     pref[1]=1;
     for(ll i=2; i <= n; i++){

          f(j,0,k){

               ll R = r[j][0], L = r[j][1]+1;
               dp[i] = (dp[i] + (i-R>0?pref[i-R]:0) - (i-L>0?pref[i-L]:0) + mod)%mod;

          }
          pref[i] = (pref[i-1] + dp[i] )%mod;

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








