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
ll const mod = 1e9;
ll const inf = 1e17;
ll const maxn = 1e5+1;



void solve()
{
      ll n,m ; cin >> n >> m;

      ll a[n]; f(i,0,n) cin >> a[i];
      ll b[m]; f(i,0,m) cin >> b[i];

      mat dp = cn(n+1,m+1);
      for(ll i = 1; i <= n; i++){
            dp[i][0] = i;
      }
      for(ll i = 1; i <= m; i++){
            dp[0][i] = i;
      }

      for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= m; j++){

                  if( a[i-1]!=b[j-1] )
                        dp[i][j] = 1 + dp[i-1][j-1];
                  else
                        dp[i][j] = dp[i-1][j-1];
                  dp[i][j] = min({dp[i][j], dp[i-1][j] + 1, dp[i][j-1] + 1});

            }
      }
      cout << dp[n][m] << endl;
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