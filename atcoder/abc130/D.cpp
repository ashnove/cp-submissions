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

void solve()
{
      ll n,k; cin >> n >> k;

      ll a[n]; f(i,0,n) cin >> a[i];
      f(i,1,n) a[i]+=a[i-1];
      ll ans = 0;
      for(ll i = 0; i < n; i++){

            ll ind = lower_bound(a,a+n, (i==0?0:a[i-1])+k) -a;
            ll cur = max(0ll, n-ind);
            ans+=cur;

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

/*
while(!pq.empty()){
            cout << pq.top().second << " " << pq.top().F << endl;;
            pq.pop();
      }
      */