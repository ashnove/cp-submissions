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
#define what_is(x) cerr << #x << " is " << x << endl;
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll, pair<ll,ll>> &a,  const pair<ll, pair<ll,ll>> &b){ 
    if(a.first > b.first ) return 1;
    if( a.first==b.first && a.S.S > b.S.S ) return 1;
    return 0;
}

ll const mod = 1e9+7;
ll const inf = 1e16;
ll const maxn = 2e5+1;
void solve()
{
      ll n; cin >> n;

      array<ll,3> rings[n], dsRings[n];
      for(ll i = 0; i < n; i++){
            cin>>rings[i][1] >> rings[i][0] >> rings[i][2];
      }
      sort(rings,rings+n);
      ll it = 0;
      for(ll i = 1; i < n; i++){
            if(rings[i][0] == rings[i-1][0]){
                  rings[i][1] = min(rings[i][1], rings[i-1][1]);
                  rings[i][2] += rings[i-1][2];
            }else{
                  dsRings[it][0] = rings[i-1][0];
                  dsRings[it][1] = rings[i-1][1];
                  dsRings[it++][2] = rings[i-1][2];
            }
      }
      dsRings[it][0] = rings[n-1][0];
      dsRings[it][1] = rings[n-1][1];
      dsRings[it++][2] = rings[n-1][2];
      // what_is(it)
      reverse(dsRings, dsRings+it);
      stack<ll> op;
      ll dp[it] = {0};
      ll ans = 0;
      for(ll i = 0; i < it; i++){
            while(!op.empty() && dsRings[i][0] <= dsRings[op.top()][1] )
                  op.pop();
            dp[i] = (!op.empty()?dp[op.top()]:0) + dsRings[i][2];
            op.push(i);
            ans = max(dp[i],ans);
      }
      
      cout << ans << endl;
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
            /**/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}          