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
      ll h,w,k; cin >> h >> w >> k;

      string s[h];
      for(ll i = 0; i<h; i++)
            cin >> s[i];
      ll row_cnt[h]={0};
      for(ll i = 0; i<h; i++){
            for(ll j = 0; j<w; j++)
                  if(s[i][j]=='#') row_cnt[i]++;
      }

      mat ans = cn(h, w);
      ll it=k, ind=-1;
      bool f = 1;
      for(ll i = 0; i < h; i++ ){
            while(f && i<h && row_cnt[i]==0){
                  ind = i,i++;
            }f = 0;
            if(row_cnt[i]==0){
                  for( ll j = 0; j < w; j++ ){
                        ans[i][j] = ans[i-1][j];
                  }
                  continue;
            }
            for( ll j = 0; j < w; j++ ){

                  ans[i][j] = it;
                  if( s[i][j] == '#' && row_cnt[i]>1 )
                        it--,row_cnt[i]--;
            }
            it--;
      }
      for(ll i = 0; i <= ind; i++){
            for(ll j = 0; j < w ; j++ ){
                  ans[i][j] = ans[ind+1][j];
            }
      }

      for(ll i = 0; i < h; i++){
            for(ll j = 0; j < w ; j++ ){
                  cout << ans[i][j] << " ";
            }
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