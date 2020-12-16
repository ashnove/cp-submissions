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
ll const mod = 998244353;
ll const inf = 1e6+1;
ll const maxn = 5e5+1;

void solve()
{     
      
      ll n,k; cin >> n >> k;
      vector<ll> vv;
      ll a[n+1];
      map<ll,ll> used;
      for(ll i = 1; i<=n; i++)
            cin >> a[i];

      ll cur = a[1];
      used[1]=1;
      vv.pb(1);
      while(used[cur]==0 ){
            vv.pb(cur);
            used[cur]=1;
            cur = a[cur];
      }
      ll idx; f(i,0,vv.size())if(vv[i]==cur)idx = i;
      ll pos = idx;
      pos += (k-idx)%(vv.size()-idx);
      cout << vv[min(k,pos)] << endl;
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