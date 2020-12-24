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
   
void solve()
{      
      
      ll n; cin >> n;
      ll a[n],b[n];
      f(i,0,n) {cin >> a[i], b[i]=a[i];}
      sort(a,a+n);
      sort(b,b+n);
      f(i,1,n) b[i]+=b[i-1];
      ll till[n];
      till[n-1]=n-1;
      for(ll i = n-2; i>=0; i--)
            if( b[i]*2 >= a[i+1] )
                  till[i]=till[i+1];
            else
                  till[i]=i;

      ll ans=0, sum = 0;
      f(i,0,n){
            sum += a[i];
            if(i<n-1){
                  if( a[i+1]<=2*sum ){
                        if(till[i+1]==n-1){
                              ans++;
                        }
                  }
            }
      }
      cout << ans+1 << endl;
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