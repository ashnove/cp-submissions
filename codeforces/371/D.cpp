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
      ll cap[n];
      for(ll i = 0; i < n ; i++)
            cin >> cap[i];
      
      ll m; cin >> m;
      set<ll> req;
      for(ll i = 0; i < n; i++)
            req.insert(i);
      ll is[n]={0};
      for(ll i = 0; i < m; ++i){
            ll ch; cin >> ch;
            if(ch==1){
                  ll x, pour;
                  cin >> x >> pour;
                  x--;
                  if(req.size()==0)continue;
                  auto at = req.lower_bound(x);
                  // cout << "fill at " << x << " with = " << pour << endl; 
                  while(at != req.end() && pour>0){                              
                        ll fill = min(cap[*at] - is[*at], pour);
                        is[*at] += fill;
                        pour -= fill;
                        ll pp = *at;
                        if(is[*at]==cap[*at])
                              req.erase(*at);
                        if(req.size()==0)goto outer;
                        at = req.lower_bound(pp);
                  }
            }     
            else{
                  ll show; cin >> show;
                  cout << is[show-1] << endl;
            }outer :
            ;
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
          /**/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}     