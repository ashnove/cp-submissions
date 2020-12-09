/*
* @author : ashnove
*/
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
ll  mod = 1000000007;
ll const inf = 1e17;
ll const maxn = 1e5+1;


void solve()
{      

      ll n; cin >> n;
      ll mons[n+1], heroes[n];
      for(ll i = 0; i<n+1; i++)
            cin >> mons[i];
      for(ll i = 0; i<n; i++)
            cin >> heroes[i];
      ll ans=  0;
      for(ll i = 0; i < n; i++ ){

            ans += mons[i]+mons[i+1];
            ll rem = max(0ll, mons[i]+mons[i+1] - heroes[i]);
            mons[i+1] = min(mons[i+1], rem);
            rem -= mons[i+1];
            mons[i] = min(mons[i], rem);
            ans -= mons[i]+mons[i+1];
      }
      cout << ans << endl;
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