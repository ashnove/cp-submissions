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
ll const maxn = 5e5+5;

void solve()
{     
      ll n; cin >> n;

      vector< pair<ll,ll> > vv;
      f(i,0,n){
            ll x,y; cin >> x >> y;
            vv.pb({x,y});
      }
      double tot = 0.0;
      vector<ll> per;
      f(i,0,n) per.pb(i);
      do{
            for(ll i = 0; i < n-1; i++ ){
                  ll j = per[i], k = per[i+1];
                  double dx = vv[j].F-vv[k].F;
                  double dy = vv[j].S-vv[k].S;
                  tot += pow( dx*dx + dy*dy, 0.5);
            }
      }while(next_permutation(per.begin(), per.end()));

      double fac = 1.0;
      for(ll i =1 ;i<=n; i++)
            fac*=i;

      cout <<  fixed << setprecision(10) << tot/fac <<endl;

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