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
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 1e5+1;

struct The{
      ll cnt, fence, pos;
};
char max(char a, char b){
      if(a>b)
            return a;
      return b;
}
void solve()
{      
      
      ll n,m,k; cin >> n >> m >> k;

      ll a[n+1]={0},b[m+1]={0};
      for(ll i = 1; i<=n; i++){
            cin >> a[i];
            a[i]+=a[i-1];
      }
      for(ll i = 1; i<=m; i++){
            cin >> b[i];
            b[i]+=b[i-1];
      }

      ll L = 0, R=0;
      for(ll i = 1; i<=n; i++){
            if( a[i] <= k )
                  R = i;

      }
      ll ans = R;
      for(ll i = R; i>=0;i--){

            while(L+1<=m && a[i]+b[L+1]<=k){
                  L++;
            }
            ans = max(ans, L+i);
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