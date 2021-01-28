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
ll const maxn = 5e5+1;

void solve()
{
      ll n,d; cin >> n >> d;

      for(ll i = 0; i<n; i++){
            ll x; cin >>x;

            if(x/d > 0){
                  ll rem = x%d;
                  ll cnt = x/d;
                  bool ok = 1;
                  for(ll j = d; j<=min(cnt,10ll)*d; j+=d){

                        if( (j%10)+rem == d ){
                              // cout << j << " ";
                              cout << "YES\n";
                              ok = 0;
                              break;
                        }

                  }
                  if(ok){
                        bool ok2=1;
                        for(ll j = d*10; j <= cnt*d; j*=10){
                              ok = 0;
                        }
                        if(ok)cout << "NO\n";else cout << "YES\n";
                  }
                  // if( rem%(10-d)==0 ){
                  //       ll c2 = rem/(10-d);
                  //       if( c2<=cnt-1)
                  //             cout << "YES\n";
                  //       else cout << "NO\n";
                  // }
                  // else cout << "NO\n";
            }
            else cout << "NO\n";
      }
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
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      return 0;
}      