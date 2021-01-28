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
// ll const mod =  63018038201;4
// 1125899906842597
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 5e3+1;

void solve()
{
      // n = 10^5;
      ll n; cin >> n;
      ll a[n], sum = 0;
      f(i,0,n){
            cin >> a[i];
            sum += a[i];
      }
      ll val = sum/n;
      ll rem = sum%n;
      ll ans[n];
      fill(ans, ans+n, val);
      for(ll i = n-1; i>=n-rem; i--)
            ans[i]++;
      ll res = 0;
      sort(a,a+n);
      for(ll i = 0; i<n; i++)
            res += abs(a[i]-ans[i]);
      // cout << val << endl;
      cout << res/2 << endl;
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
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      return 0;
}     