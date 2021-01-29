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
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
//me19U10584
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+1;

void solve()
{            
      ll n,k; cin >> n >> k;

      ll a[n]; f(i,0,n) cin >> a[i];

      ll sum = 0;
      sum = a[0];
      ll ans = 0;
      // a[0]=0;
      for(ll i = 1; i<n; i++){
            
            if( a[i]*100  <= k*sum){
                  sum += a[i];
            }
            else{
                  ll ch = ceil( (double)(a[i]*100)/k ) - sum;                 
                  // cout << i << " " << ch << endl;
                  ans +=  ch ;
                  sum += ch + a[i];
                  // cout << " " << sum << endl;
            }
      }

      // if( a[n-1]*100 > k*sum ){
      //       ll ch = floor( (double)(100*a[n-1] - k*sum)/100.0 );
      //             ans += ch;
      //             sum += a[n-1]+ch;
      //             cout << " " << sum << endl;
      // }
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
            // fact();
            ll t;
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
                  // cout << "Case #" <<testcases+1<<": ";
                  solve();
            }
 
 
    return 0;
}     