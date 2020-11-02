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
      ll a[n];
      for(ll i =0; i<n; i++)
            cin >> a[i];

      ll inc[n], dec[n];
      inc[n-1]=dec[n-1]=n-1;

      for(ll i = n-2; i >=0; i--){
            if(a[i]<=a[i+1])
                  inc[i]=inc[i+1];
            else
                  inc[i]=i;
            if(a[i]>=a[i+1])
                  dec[i]=dec[i+1];
            else
                  dec[i]=i;
      }

      ll it = 0, ans = 0;
      while(it<n){
            if(inc[it]>dec[it])
                  it = inc[it] + 1;
            else
                  it = dec[it] + 1;
            ans++;
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