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
ll const maxn = 5e5+1;

void solve()
{
      
      ll n; cin >> n;

      ll tot = (1ll<<n);
      ll a[tot+1];
      set<ll> peeps;
      f(i,0,tot){ 
            cin >> a[i+1];
            peeps.insert(i+1);
      }
      ll lastmanOut;
      for(ll i = 1; i <= n; i++){

            vector<ll> vv;
            for(auto e : peeps)
                  vv.pb(e);
            for(ll j = 0; j<vv.size(); j+=2){
            auto ind1 = vv[j];
            auto ind2 = vv[j+1];
      
            if( a[ind1] > a[ind2] ){
                  lastmanOut = ind2;
                  peeps.erase(ind2);
            }
            else{
                  lastmanOut = ind1;
                  peeps.erase(ind1);
            }
            // cout << j << " " <<  p1 << " " << p2 << " " << *ind1 << " " << *ind2 << " " << lastmanOut << endl;
            if(peeps.size()==1){
                  cout << lastmanOut << endl;
                  return;
            }}
            // for(auto e : peeps)
            //       cout << e << " ";
            // nl;
      }

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