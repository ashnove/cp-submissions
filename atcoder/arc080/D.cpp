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
ll const mod = 1e9;
ll const inf = 1e17;
ll const maxn = 1e5+1;


void solve()
{
      ll h,w; cin >> h >> w;
      ll n; cin >> n;
      ll col[n];
      for(ll i = 0; i<n; i++)
            cin >> col[i];
      ll ans[h][w];
      bool turn = 1;
      ll it = 0;
      for(ll i = 0; i<h; i++){

            if(turn){
                  turn^=1;
                  for(ll j = 0; j<w; ){

                        while(j < w && col[it]){
                              ans[i][j] = it+1;
                              j++, col[it]--;
                        }
                        if(col[it]==0)it++;

                  }
            }
            else{
                  turn^=1;
                  for(ll j = w-1; j>=0 ; ){

                        while(j>=0 && col[it]){
                              ans[i][j] = it+1;
                              j--, col[it]--;
                        }
                        if(col[it]==0)it++;

                  }
            }
            
      }
      for(ll i = 0; i<h; i++){
            for(ll j = 0; j < w; j++ )
                  cout << ans[i][j] << " ";
            nl; 
      }
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