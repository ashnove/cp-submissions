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

bool p[maxn];
vector<ll> vv;
void sieve(){

      fill(p, p+maxn, 1);
      for(ll i = 2; i*i < maxn; i++){
            if(p[i]==1){
                  for(ll j = i*i; j < maxn; j+=i)
                        p[j] = 0;
            }
      }

      f(i,2, maxn){
            if(p[i])
                  vv.pb(i);
      }
}
void solve()
{      
      // for(auto e : vv)
      //       cout << e << endl;
      ll d; cin >> d;

      ll f = 1+d;

      ll ind1 =  lower_bound( vv.begin(), vv.end(), f ) - vv.begin();

      f = vv[ind1] + d;
      ll ind2 =  lower_bound( vv.begin(), vv.end(), f ) - vv.begin();

      cout << vv[ind1]*vv[ind2] << endl;

}

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
            sieve();
          ll t;
          /*/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}     