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
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
//me19U10584
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+1;

void solve()
{
      ll x,y; cin >> x >> y;
      ll a = abs(x), b = abs(y);

      string s; cin >> s;
      char ch, ch2;
      if(x>=0)ch='R';
      if(x<0)ch='L';
      if(y>=0)ch2='U';
      if(y<0)ch2='D';
      ll p,q;p=q=0;
      for(auto e : s){
            if(e==ch)p++;
            if(e==ch2)q++;
      }
      if(p>=a && q>=b)cout << "YES\n";
      else cout << "NO\n";
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
            // fact();
            ll t;
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
                  // cout << "Case #" <<testcases+1<<": ";
                  solve();
            }
 
 
    return 0;
}     