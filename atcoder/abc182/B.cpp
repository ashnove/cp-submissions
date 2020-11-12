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
//me
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 1e3+1;

  
void solve()      
{     
      
      ll n; cin >> n;

      ll a[n]; f(i,0,n) cin >> a[i];

      map<ll,ll> cnt;
      f(i,0,n){

            for(ll j = 2; j <= a[i]; j++){
                  bool ok = 0;
                  while( a[i]%j == 0 )
                        a[i]/=j, ok = 1;
                  if(ok) cnt[j]++;
            }


      }   
      ll ans = 0, maxm = 0;
      for(pair<ll,ll> e : cnt){

            if( maxm <= e.S )
                  maxm = e.S, ans = e.F;

      }

      cout << ans << endl;
                                       
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