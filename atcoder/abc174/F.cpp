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
ll const maxn = 5e5+5;

ll tree[maxn], n;
ll cur_record[maxn], last_seen[maxn];

void update(ll i, ll val)
{
      while(i<=n){
            tree[i]+= val;
            i += i & -i;
      }
            
}

ll query(ll i)
{
      ll res  = 0;
      for(; i>0; i-= i & -i)
            res += tree[i];
      return res;
}
ll rquery(ll a, ll b)
{
      return (query(b) - query(a-1));
}

void solve()
{     
      ll nQ; cin >> n >> nQ;
      ll col[n+1];
      f(i,0,n) cin >> col[i+1];

      
      fill(cur_record, cur_record+n+2, 0);
      fill(last_seen, last_seen+n+2, n+1);

      vector<pair<ll,ll>> all[n+1], queries;
      map< pair<ll,ll> , ll > ans;

      while(nQ--){
            ll L, R; cin >> L >> R;
            all[L].pb({L,R});
            queries.pb({L,R});
      }

      for(ll i = n; i > 0; i--){
            update(last_seen[col[i]],-1);
            update(i,1);
            last_seen[ col[i] ] = i;

            for( pair<ll,ll> e : all[i]){
                  ans[{e.F, e.S}] = rquery(e.F, e.S);
            }
      
            
      }
      for( pair<ll,ll> e : queries){
            cout << ans[e] << endl;
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