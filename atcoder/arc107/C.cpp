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
ll const mod = 998244353;
ll const inf = 1e18;
ll const maxn = 1e3+1;

ll f[maxn];
void fact(){
      f[0]=1;
      for(ll i = 1; i< maxn; i++)
            f[i] = (f[i-1]*i)%mod;
}

ll par_row[maxn], par_col[maxn];
ll Rank1[maxn], Rank2[maxn];

ll find1(ll x){
      if( par_row[x] < 0)
            return x;
      return par_row[x] = find1(par_row[x]);
}
ll find2(ll x){
      if( par_col[x] < 0)
            return x;
      return par_col[x] = find2(par_col[x]);
}

void merge1(ll a, ll b){
      a = find1(a), b = find1(b);
      if(a==b)return;
      if(Rank1[a] > Rank1[b]){
            par_row[b]= a;
            Rank1[a]+=Rank1[b];
      }
      else{
            par_row[a]=b;
            Rank1[b]+=Rank1[a];
      }
}

void merge2(ll a, ll b){
      a = find2(a), b = find2(b);
      if(a==b)return;
      if(Rank2[a] > Rank2[b]){
            par_col[b]=a;
            Rank2[a]+=Rank2[b];
      }
      else{
            par_col[a]=b;
            Rank2[b]+=Rank2[a];
      }
      
      //par_col[b]=a;
}
  
void solve()      
{      
      fact();

      ll n, K; cin >> n >> K ;
      fill(par_row, par_row+n, -1);
      fill(par_col, par_col+n, -1);
      fill(Rank2, Rank2+n, 1);
      fill(Rank1, Rank1+n, 1);

      ll a[n][n];
      f(i,0,n) f(j,0,n) cin >> a[i][j];

      f(i,0,n){

            f(j,i+1,n){
                  bool ok = 1;
                  f(k,0,n){

                        if( a[j][k]+a[i][k]> K )
                              ok = 0;

                  }
                  if(ok){
                        merge1(i,j);
                  }
            }

      }

      f(i,0,n){

            f(j,i+1,n){
                  bool ok = 1;
                  f(k,0,n){

                        if( a[k][i]+a[k][j]> K )
                              ok = 0;

                  }
                  if(ok){
                        merge2(i,j);
                  }
            }

      }

      ll ans= 1;

      f(i,0,n){
            if(par_row[i]<0)
                  ans = (ans*f[abs(Rank1[i])])%mod;
      }
      f(i,0,n){
            if(par_col[i]<0)
                  ans = (ans*f[abs(Rank2[i])])%mod;
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