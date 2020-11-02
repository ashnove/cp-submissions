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
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
//me
ll const mod = 998244353;
ll const inf = 1e18;
ll const maxn = 5e5+1;


void solve()
{      
      ll k,n; cin >> k >> n;
      ll a[n];
      f(i,0,n) cin >> a[i];
      if(k >= n)
      {
            cout << 0 << endl;
            return;
      }
      sort(a,a+n);
      vector<ll> vv;
      ll ans = 0;
      f(i,0,n-1) vv.pb(a[i+1]-a[i]), ans += a[i+1]-a[i];
      sort(vv.begin(), vv.end());
      reverse(vv.begin(), vv.end());
      
      f(i,0,k-1)
            ans-=vv[i];
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