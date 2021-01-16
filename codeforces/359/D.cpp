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
ll const maxn = 1e5+1;
class The{
public:
      ll up, down;
};

void solve()
{
      ll n; cin >> n;

      ll rangeMinimum[n][20];
      ll rangeGcd[n][20];
      ll a[n+1]; 
      f(i,0,n){ 
            cin >> a[i];
            rangeMinimum[i][0] = a[i]; 
            rangeGcd[i][0] = a[i]; 
      }
      ll log[n+1]={0};
      for(ll i = 2; i<=n; i++)
            log[i] = 1 + log[i/2];

      for(ll j = 1; j < 20; j++ ){
            for(ll i = 0; i + (1ll << j) <= n; i++ )
                  rangeMinimum[i][j] = min(rangeMinimum[i][j-1], rangeMinimum[i + (1ll << (j-1))][j-1]);
      }
      for(ll j = 1; j < 20; j++ ){
            for(ll i = 0; i + (1ll << j) <= n; i++ )
                  rangeGcd[i][j] = __gcd(rangeGcd[i][j-1], rangeGcd[i + (1ll << (j-1))][j-1]);
      }

      ll low = 1, high = n, maxlen = 0;
      while(low <= high){
            ll mid = (low + high )/2;

            bool ok = 0;
            for(ll i = 0; i+mid-1<n; i++){
                  ll r = log[mid]; 
                  ll curMin = min( rangeMinimum[i][r], rangeMinimum[i+mid-(1ll << r)][r] );
                  ll curGcd = __gcd( rangeGcd[i][r], rangeGcd[i+mid-(1ll << r)][r] );
                  if( curMin == curGcd )
                        ok = 1;
            }
            if(ok){
                  maxlen = mid;
                  low = mid + 1;
            }else high = mid - 1;
      }
      vector<ll> ans;
      for(ll i = 0; i+maxlen-1<n; i++){
            ll r = log[maxlen]; 
            ll curMin = min( rangeMinimum[i][r], rangeMinimum[i+maxlen-(1ll << r)][r] );
            ll curGcd = __gcd( rangeGcd[i][r], rangeGcd[i+maxlen-(1ll << r)][r] );
            if( curMin == curGcd )
                  ans.pb(i+1);
      }
      cout << ans.size() << " " << maxlen - 1 << endl;
      for(ll e : ans)
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
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     