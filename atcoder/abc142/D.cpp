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
ll const maxn = 5e5+1;

ll Rank[maxn], par[maxn];
ll find(ll x){
      if(par[x]<0)
            return x;
      return par[x] = find(par[x]);
}
void merge(ll a ,ll b){
      a = find(a), b = find(b);
      if(a==b) return;

      if(Rank[a]>Rank[b]){
            par[b] = a;
            Rank[a]+= Rank[b];
      }
      else{
            par[a] = b;
            Rank[b] += Rank[a];
      }
}
void solve()
{      

      ll a,b; cin >> a >> b;

      set<ll> a_factors;
      for(ll i = 1; i*i<=a; i++){
            if(a%i==0){
                  a_factors.insert(i);
                  a_factors.insert(a/i);
            }
      }
      ll ans=1;
      ll common = __gcd(a,b);
      for(ll i =2; i*i<=common; i++){
            bool ok = 0;
            while(common%i==0)
                  common/=i, ok = 1;
            if(ok)ans++;
      }
      if(common>2)ans++;

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