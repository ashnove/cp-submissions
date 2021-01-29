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
bool sortmahstyle(const pair<ll, pair<ll,ll>> &a,  const pair<ll, pair<ll,ll>> &b){ 
    if(a.first > b.first ) return 1;
    if( a.first==b.first && a.S.S > b.S.S ) return 1;
    return 0;
}
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+1;
class The{
public:
      ll up, down;
};
void solve()
{
      ll n; cin >> n;

      ll c[n]; f(i,0,n) cin >> c[i];
      ll a[n],b[n];
      f(i,0,n) cin >> a[i];
      f(i,0,n) cin >> b[i];

      ll dp[n]={0};
      ll ans = 0;
      for(ll i = 1; i<n; i++){

            if(dp[i-1]==0 || (a[i]==b[i])){
                  ans = max(ans, dp[i-1]);
                  dp[i] = max( c[i], abs(a[i]-b[i])+1 + c[i]);
                  // cout <<  << " ";
            }
            else
            dp[i] = max( {dp[i-1] - abs(a[i]-b[i])+1+ c[i], abs(a[i]-b[i])+1 + c[i] });
            ans = max(ans, dp[i]);

      }
      
      cout << max(dp[n-1], ans) << endl;

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
            ll t;
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     