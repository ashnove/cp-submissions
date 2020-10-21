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
      ll h,w; cin >> h >> w;
      string s[h];
      f(i,0,h) cin >> s[i];

      ll dp[h+1][w+1];
      f(i,0,h+1)
            fill(dp[i], dp[i]+w+1, inf);
      // w <- w = +0
      // w <- b = +1
      // b <- w = +0
      // b <- b = +0
      dp[1][1] = (s[0][0]=='#'?1:0);

      for(ll i = 1; i <= h; i++) {

            for(ll j = 1; j <=w; j ++){

                  if(i==1&&j==1) continue;
                  char cur = s[i-1][j-1];
                  if(i-2>=0){
                        if(cur=='.')
                              dp[i][j] = dp[i-1][j];
                        else
                              dp[i][j] = dp[i-1][j] + (s[i-2][j-1]=='.'?1:0);
                        
                  }
                  if(j-2>=0){
                        if(cur=='.')
                              dp[i][j] = min(dp[i][j],dp[i][j-1]);
                        else
                              dp[i][j] = min(dp[i][j],dp[i][j-1] + (s[i-1][j-2]=='.'?1:0));
                        
                  }
            }

      }
      
      cout << dp[h][w] << endl;
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