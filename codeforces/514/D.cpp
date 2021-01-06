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
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b){ 
    if(a.first < b.first ) return 1;
    if( a.first==b.first && a.S != b.second ) return 1;
    return 0;
}
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e2+1;
void solve()
{      

      ll n,m,K; cin >> n >> m >> K;

      ll droid[n][m];
      ll st[m][n][23];

      for(ll i = 0; i < n; i++)
            for(ll j = 0; j < m; j++ ){
                  cin >> droid[i][j];
                  st[j][i][0] = droid[i][j];
            }

      ll log[n+1]={0};
      for(ll i = 2; i<=n; i++)
            log[i] = 1 + log[i/2];
      for(ll k = 0; k < m; k++ ){
            for(ll j = 1; j <= 22; j++){
                  for(ll i = 0; i + (1ll << j) <= n; i++ ){
                        st[k][i][j] = max( st[k][i][j-1], st[k][i + (1ll<<(j-1)) ][j-1] );
                  }
            }
      }

      ll low = 1, high = n;
      ll res;
      vector<ll> ans;
      while(low <= high){

            ll mid = (low + high)/2;

            ll req = inf, tsum = inf;
            vector<ll> vv1;
            for(ll i = 0; i+mid-1<n; i++){

                  vector<ll> vv2;
                  ll sum = 0;
                  for(ll jj = 0; jj < m; jj++){

                        ll j = log[mid];
                        ll val = max( st[jj][i][j], st[jj][ i + mid - (1ll << j)][j]);
                        sum += val;
                        // cout << val << endl;
                        vv2.pb(val);
                  }
                  if(tsum > sum){
                        tsum =sum;
                        vv1.clear();
                        for(auto e : vv2)
                              vv1.pb(e);

                  }
                  tsum = min(tsum , sum);
            }

            if( tsum <= K){
                  res = mid;
                  ans.clear();
                  for(auto e : vv1)
                        ans.pb(e);
                  low = mid + 1;
            }else high = mid - 1;

      }
      if(ans.empty()){
            f(i,0,m)
            cout << 0 << " ";

            return;
      }
      for(auto e : ans)
            cout << e << " ";
      nl;

}     

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
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