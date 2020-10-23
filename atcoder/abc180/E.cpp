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
ll score(ll a, ll b, ll c, ll x, ll y, ll z)
{
      ll res=0;
      res += abs(x-a);
      res += abs(y-b);
      res += max(0ll, z-c);
      return res;
}
void solve()
{     
      
      ll n; cin >> n; 
      vector<ll> a(n), b(n), c(n);

      f(i,0,n)
            cin >> a[i] >> b[i] >> c[i];

      ll tot = (1<<n);
    
      //dp[i][j] = the min cost to traverse through all the points
      //           in the set i ending at vertex j;
      vector<vector<ll>> dp(tot, vector<ll>(n, inf));
      
      for(ll i=1; i<n; i++)
            dp[(1<<i)][i] = score(a[0], b[0], c[0], a[i], b[i], c[i]);


      for(ll i = 0; i < tot ; i++){

            for(ll j = 0; j< n; j++ ){

                  if( i & (1<<j) ){

                        for(ll k = 0; k<n; k++){

                              if( (i & (1<<k)) == 0){
                                    ll point = score(a[j], b[j], c[j], a[k], b[k], c[k]);
                                    dp[i | (1<<k)][k] = min(dp[i | (1<<k)][k], dp[i][j]+point);
                              }

                        }

                  }

            }

      }
      cout << dp[tot -1][0] << endl;




}
    
int main(int argc, char const *argv[]) {
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