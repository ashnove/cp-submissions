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
ll const maxn = 2e6+1;

ll tree[maxn], n;

void update(ll i, ll val)
{
    for(; i<=n; i += i & -i )
        tree[i]+= val;
}

ll query(ll i)
{
    ll res = 0;
    for(; i>0; i -= i & -i)
        res += tree[i];

    return res;
}
void solve()
{      
      ll n; cin >> n;
      ll sum = 0;
      ll a[n]; f(i,0,n) {cin >> a[i]; sum+=a[i];}
      ll m; cin >> m;
      ll q[m]; f(i,0,m) cin >> q[i];

      sort(a,a+n);
      reverse(a,a+n);
      ll ans=inf;
      f(i,0,m){
            cout << sum-a[q[i]-1] << endl;
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