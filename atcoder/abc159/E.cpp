#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
ll const inf = 1e18;
ll const maxn = 5e5+5;

void solve()
{     
      ll h,w,k; cin >> h >> w >> k;

      string s[h]; f(i,0,h) cin >> s[i];
      ll fans = LLONG_MAX;
      for(ll i = 0 ; i < (1<<(h-1)); i++){

            vector<ll> grps;
            vector<pair<ll,ll>> lims;
            grps.pb(0); ll ans = 0;
            for(ll j = 0; j < 30; j++ )
                  if(i & (1<<j)){
                        grps.pb(j+1);
                        ans++;
                  }
            if(grps.back()!=h)grps.pb(h);
            ll L, R;
           
            for(ll i = 0 ; i < grps.size()-1; i++)                  
                  lims.pb({grps[i], grps[i+1]});       

            ll vertical = 0, cur=0;
            //cout << lims.size()<< endl;
            bool ok = 1;
            vector<ll> sum(lims.size(), 0);
            for(ll p = 0; p < w; p++){

                  vector<ll> cur_g(lims.size(), 0); ll it = 0;
                  for(auto e : lims){
                        L = e.F, R = e.S;
                        ll vv = 0;
                        cur=0;                  
                        for(ll q = L; q < R; q++){
                        
                              if(s[q][p]=='1')
                                    cur++;
                        }
                        cur_g[it++] = (cur);
                        if(cur  > k ) ok = 0;
                  
                  } 
                  bool tok = 0;
                  for( ll zz = 0; zz < lims.size(); zz++ ){
                        if(!ok) break;
                        if(sum[zz] + cur_g[zz] > k){
                              vertical++; tok =1;
                              break;
                        }
                        else
                              sum[zz]+= cur_g[zz];
                  
                  }
                  for(ll ii = 0; tok && ok && ii< lims.size(); ii++)
                        sum[ii] = cur_g[ii]; 

                  
            }
            if(!ok) continue;
            ll now = ans + vertical;
            fans = min(fans, now);


      }
      cout << fans << endl;
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