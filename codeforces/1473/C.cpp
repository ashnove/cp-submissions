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
bool sortmahstyle(const pair<ll, pair<ll,ll>> &a,  const pair<ll, pair<ll,ll>> &b){ 
    if(a.first > b.first ) return 1;
    if( a.first==b.first && a.S.S > b.S.S ) return 1;
    return 0;
}
ll const mod = 1e9+7;
ll const inf = 1e9;
ll const maxn = 1e5+1;
class The{
public:
      ll up, down;
};

void solve()
{
      ll n,k; cin >> n >> k;
      ll a[n];
      f(i,0,k)
            a[i]=i+1;
      ll q = k;
      f(i,k,n)
            a[i]=--q;

      ll b[n];
      ll it = 1;
      for(ll i = 0; i< 2*k-n-1; i++)
            b[i]=it++;
      ll p = k;
      for(ll i = it-1; i<k; i++){
            b[i] = p--;
      }
      p++;
      for(ll i = k; i<n; i++)
            b[i] = ++p;
      ll ans[k]={0};
      f(i,0,n){
            ans[a[i]-1] = b[i];
      }
      f(i,0,k)
            cout << ans[i] << " ";
      nl;
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
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     