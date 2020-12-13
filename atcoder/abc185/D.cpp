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
ll const mod = 1e9;
ll const inf = 1e17;
ll const maxn = 1e5+1;



void solve()
{
      ll n,m ; cin >> n >> m;

      ll a[m];
      f(i,0,m) cin >> a[i];
      sort(a,a+m);
      vector<ll> vv;
      ll last = 0;
      for(ll i = 0; i<m; i++){
            vv.pb(a[i]-last - 1);
            last = a[i];
      }    
      ll ans = LLONG_MAX;
      vv.pb(n-last);
      for(auto e:vv){
            // cout << e << endl;
            if(e!=0)ans = min(ans,e);
      }
      ll tot = 0;
      for(auto e:vv){
            if(e!=0){

                  tot += (e+ans-1)/ans;

            }
      }
      cout << tot << endl;
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