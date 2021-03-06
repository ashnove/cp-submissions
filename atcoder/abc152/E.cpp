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
#define what_is(x) cerr << #x << " is " << x << endl;
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll, pair<ll,ll>> &a,  const pair<ll, pair<ll,ll>> &b){ 
    if(a.first > b.first ) return 1;
    if( a.first==b.first && a.S.S > b.S.S ) return 1;
    return 0;
}

ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 1e6+1;
class edge{
public:
      ll a,b,w;
};

ll modpow(ll a, ll b){
      ll res = 1;
      while(b){
            if(b&1) res = (res * a)%mod;
            a = a*a%mod;
            b/=2;
      }
      return res;
}
ll inv(ll x){
      return modpow(x, mod - 2);
}
void solve()
{
            
      ll n; cin >> n;
      ll a[n],b[n]; f(i,0,n) {cin >> a[i], b[i]=a[i];}

      map<ll,ll> tot;
            
      for(ll i = 0 ;i < n; i++){
            ll val = a[i];
            map<ll,ll> temp;
            for(ll j = 2; j*j <= maxn; j++){
                  while(val%j==0)
                        val/=j, temp[j]++;
            }
            if(val>2)
                  temp[val]=1;

            for(auto e : temp){
                  tot[e.F] = max(tot[e.F], e.S);
            }
            
      }
      
      ll lcm = 1;
      for(auto e : tot){
            lcm = (lcm * modpow(e.F, e.S)) % mod;
      }
      ll ans = 0;
      for(ll i = 0; i < n; i++){
            ans = ( ans + (lcm *inv(b[i]))%mod ) % mod;
      }
      cout << ans << endl;
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
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     