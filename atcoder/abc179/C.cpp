/*
 * Author: ashnove
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

#define mat vector<vector<ll>>
mat cn(ll n, ll m)
     {return vector< vector<ll> >(n, vector<ll>(m));}

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
ll const mod = 1e6+3;
ll const inf = 1e18+1;
ll const maxn = 2e1+2;
ll powmod(ll a, ll b)
{
     ll res = 1;
     while(b){
          if(b&1) res = ( res * a) % mod;
          a = (a*a) % mod;
          b/=2;
     }
     return res;
}
void solve()
{
     ll n; cin >> n;
     ll ans  = 0;
     f(i,1,n+1){
          f(j,1,n+1){
               if(i*j < n)
                    ans++;
               else
                    break;
          }
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








