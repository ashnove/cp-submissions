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
      
      string s; cin >> s;

      ll n = s.size();
      ll a[n];
      f(i,0,n){ 
            a[i] = s[i] - '0';
      }
      ll ans = 0;
      for(ll i = 1; i<(1<<n); i++){

            ll cur =0, cnt = 0;
            for(ll j = 0; j<n; j++){
                  if( i & (1<<j) )
                        cur+=a[j], cnt++;
            }
            if( cur % 3 == 0 ){
                  ans = max(ans, cnt);
            }

      }
      if(ans == 0) cout << -1 << endl;
      else
      cout << n - ans << endl;
                                       
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