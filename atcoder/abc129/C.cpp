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
ll r,s,p; 
ll score(char ch){
      if(ch=='r')return p;
      if(ch=='p')return s;
      if(ch=='s')return r;
}

void solve()
{     
      ll n,m; cin >> n >> m;
      map<ll,ll> broken;
      f(i,0,m){
            ll x; cin >> x;
            broken[x]++;
      }
      ll dp[n+1]={0};
      dp[0]=dp[1]=1;

      for(ll i = 2; i<=n; i++){

            if(!broken[i]){
                  if(!broken[i-1])
                        dp[i] = dp[i-1];
                  if(!broken[i-2])
                        dp[i] = (dp[i]+dp[i-2])%mod;
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