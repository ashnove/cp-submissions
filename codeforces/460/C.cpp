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
      ll n,m,w; cin >> n >> m >> w;
      ll a[n];
      for(ll i = 0; i < n; i++ )
            cin >> a[i];

      ll active[n]={0};
      ll ans = 0;
      ll low = 0, high = 1000100000;
      while( low <= high ){
            ll mid = (low + high)/2;
            fill(active, active + n, 0);
            ll cur = 0, prev = 0;
            for(ll i = 0; i < n; i++ ){
                  prev += active[i];
                  if( mid > a[i] + prev  ){
                        ll newAdd = mid - a[i] - prev;
                        prev += newAdd;
                        cur += newAdd;
                        if( i + w  < n) 
                              active[i + w] -= newAdd;
                  }

            }
            if( cur <= m ){
                  ans = mid;
                  low = mid + 1;
            }else high = mid - 1;
      }      
      cout << ans << endl;
}     

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
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