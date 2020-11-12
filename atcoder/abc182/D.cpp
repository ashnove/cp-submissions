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
      ll a[n+1]={0}, b[n+1]={0}, ans[n+1]={0};

      f(i,0,n){
            cin >> a[i+1];
            b[i+1] = b[i] + a[i+1];
      }

      ans[1] = a[1];
      ll max_yet[n+1];
      max_yet[1]=b[1];
      f(i,2,n+1){
            max_yet[i] = max( b[i], max_yet[i-1] );
      }
      ll fans = a[1];

      f(i,2,n+1){

            ans[i] = b[i] + ans[i-1];
            fans = max( fans, max_yet[i]+ans[i-1] );

      }
            
      cout << max(0ll,fans) << endl;
                                       
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