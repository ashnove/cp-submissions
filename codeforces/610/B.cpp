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
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b){ 
    if(a.first < b.first ) return 1;
    if( a.first==b.first && a.S != b.second ) return 1;
    return 0;
}  
bool comp( const array<ll,3> &a, const array<ll,3> &b ){
      if( a[0] < b[0] )
            return 1;
      if( a[0] == b[0] && a[1] > b[1] ) 
            return 1;
      return 0;
}            
// ll const mod =  63018038201;4
// 1125899906842597
ll const mod = 1e9+7;
ll const inf = 1e15;
ll const maxn = 1e5+1;

void solve()
{
      ll n; cin >> n;

      ll a[n], left[n], right[n];
      left[0]=inf;
      for(ll i = 0; i < n; i++){
            cin >> a[i];
            if(i==0)left[i]=a[i];
            else
            left[i]=min(left[i-1], a[i]);
      }
      right[n-1]=a[n-1];
      map<ll,ll> mp;
      for(ll i = 0; i < n; i++){
            if(mp[left[i]]==0)mp[left[i]]=i+1;

      }
      for(ll i = n-2; i >= 0; i--){
            right[i] = min(right[i+1], a[i] );
      }
      vector<ll> v;
      for(ll i=0;i<n;i++)
            if (a[i]==right[0]) v.push_back(i);

      ll diff = 0;
      if ((v[0]+n-v[v.size()-1]-1)> diff) 
            diff=v[0]+n-v[v.size()-1]-1;
      for (int i=0;i<v.size()-1;i++)
            if ((v[i+1]-v[i]-1)>diff) 
                  diff=v[i+1]-v[i]-1;
      


      // ll ans = n*right[0] + mpR[0];
      // for(ll i = 1; i < n; i++){
      //       ll R = right[i];
      //       ll L = left[i-1];
      //       ll cur = min(R,L)*n;
      //       if(R==L) cur += mpR[i]-i;
      //       else if(R > L) cur += n-i + mp[L]-1;
      //       else cur += mpR[i]-i;

      //       ans = max(ans, cur);
      // }
      cout << right[0]*n + diff << endl;
}     

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
            ll t;
            /**/t=1;
            /*/cin >> t;/**/
            f(testcases,0,t){
               // cout << "Case " <<testcases+1<<": ";
               solve();
            } 
      return 0;
}      