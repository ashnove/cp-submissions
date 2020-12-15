/*
* @author : ashnove
*/
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
ll const inf = 1e6+1;
ll const maxn = 5e5+1;
struct The{
      ll x,y;
};
void solve()
{     
      ll n; cin >> n;

      vector<pair<ll,ll>> ans;
      set< pair<ll,ll> > used;
      if(n&1){
            for(ll i = 1; i < n; i++){
                  ans.pb({i,n});
                  used.insert({i,n});
            }
            n--;
      }
      ll L = 1, R = n;
      while(L < R){
            for(ll i = 1; i <= n; i++)
                  if(i!=L && i!=R && (!used.count({L,i}) && !used.count({i,L})))ans.pb({i,L}), used.insert({L,i}), used.insert({i,L});
            for(ll i = 1; i <= n; i++)
                  if(i!=R && i!=L && (!used.count({R,i}) && !used.count({i,R})))ans.pb({i,R}), used.insert({R,i}), used.insert({i,R});
            L++,R--;
      }
      cout << ans.size() << endl;
      for(pair<ll,ll> e : ans)
            cout << e.F << " " << e.S << endl;


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