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
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e6+1;

void solve()
{
      
      ll x,y,z; 
      cin >> x >> y >> z;
      vector<ll> a(x), b(y), c(z);
      ll A,B,C; A=B=C=0;
      for(ll i = 0; i < x; i++){
            cin >> a[i];
            A += a[i];
      }
      for(ll i = 0; i < y; i++){
            cin >> b[i];
            B += b[i];
      }
      for(ll i = 0; i < z; i++){
            cin >> c[i];
            C += c[i];
      }

      sort(a.begin(), a.end());      
      sort(b.begin(), b.end());      
      sort(c.begin(), c.end());  

      cout << A+B+C - 2*min( { A, B, C , a[0]+b[0], b[0]+c[0], c[0]+a[0] } ) << endl;    

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
