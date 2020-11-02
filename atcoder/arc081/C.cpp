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
      ll n; cin >> n;
      ll a[n]; f(i,0,n) cin >> a[i];

      map<ll,ll> cnt;
      f(i,0,n) ++cnt[a[i]];
      sort(a,a+n);
      reverse(a,a+n);
      vector<ll> ans;
      f(i,0,n){
            if(cnt[a[i]]>=4 && ans.size()==0)
                  ans.pb(a[i]), ans.pb(a[i]);
            else if(cnt[a[i]]>=2)
                  ans.pb(a[i]),cnt[a[i]]=0;
            if(ans.size()==2)
                  break;
      }
      if(ans.size()==2)
            cout << ans[0]*ans[1];
      else
            cout << 0 << endl;
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