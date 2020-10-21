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
      if(a.first != b.first)
            return 1;
      if( abs(a.S - b.S)>1)
            return 1;
      return 0;
}
//me
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 1e7+1;
void solve()
{     
      ll h,n; cin >> h >> n;
      ll a[n+1], b[n+1];
      f(i,0,n){
            cin >> a[i+1] >> b[i+1];
      }

      ll dp[h+1];
      fill(dp, dp+h+1, inf);
      dp[0]=0;
      for(ll i=1; i<=h; i++){

            for(ll j=1; j<=n; j++){

                  if(dp[(i-a[j]<=0?0:i-a[j])]<inf)
                        dp[i] = min(dp[i], dp[(i-a[j]<=0?0:i-a[j])] + b[j]);

            }

      }
      
      cout << dp[h] << endl;
}
    
int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
      //fact();
          ll t;
          /**/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}