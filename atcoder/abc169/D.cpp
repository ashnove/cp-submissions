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
ll const mod = 998244353;
ll const inf = 1e18;
ll const maxn = 1e6+1;

void solve()
{    
     ll n; cin >> n;

     vector<pair<ll,ll>> vv;
     ll N = n;
     for(ll i = 2; i*i <= N; i++){

          ll cur = 0;
          while(n%i==0)
               cur++, n/=i;

          vv.pb({i,cur});

     }
     if(n>2)
          vv.pb({n,1});
     ll cur,zz,cnt,ans = 0;
     for(pair<ll,ll> e : vv){
          //cout << e.S << endl;
          cur=0,zz= 1, cnt=0;
          while(cur+zz <= e.S )
               cur+=zz, zz++, cnt++;;
          ans+=cnt;
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








