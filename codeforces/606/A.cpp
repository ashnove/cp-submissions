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
ll const maxn = 5e5+1;

void solve()
{
     ll a,b,c; cin >> a >> b >> c;
     ll x,y,z; cin >> x >> y >> z;
     ll needs = 0, has = 0;
     if(a>x)has+=(a-x);
     else needs+=(x-a);

     ll toBeChange = has/2; has=0;
     if(b>y)has+=(b-y);
     else needs+=(y-b);
     toBeChange += has/2; has =0;
     if(c>z)has+=(c-z);
     else needs+=(z-c);
     toBeChange += has/2;
     cout << ( needs<=toBeChange?"Yes\n":"No\n" );
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