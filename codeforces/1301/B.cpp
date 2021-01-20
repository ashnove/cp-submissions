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
ll const maxn = 5e5+1;

void solve()
{      
      
      ll n; cin >> n;
      ll a[n];
      for(ll i = 0; i<n; i++)
            cin >> a[i];

      set<ll> s;
      for(ll i = 0; i<n; i++){
            if(a[i]==-1){
                  if(i-1>=0 && a[i-1]!=-1)
                        s.insert(a[i-1]);
                  if(i+1<n && a[i+1]!=-1)
                        s.insert(a[i+1]);
            }
      }
      if(s.size()==0){
            cout << "0 0\n";
            return;
      }
      // if(s.size()==1){
      //       cout << 0 << " " << *s.begin() << endl;
      //       return;
      // }
      ll k = (*s.rbegin()+*s.begin())/2;

      ll ans = 0;
      for(ll i = 0; i<n-1; i++){
            if(a[i]==-1) a[i]=k;
            if(a[i+1]==-1)a[i+1]=k;
            ans = max(ans, abs(a[i]-a[i+1]));
      }

      cout << ans << " " << k << endl;

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
          /*/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}     