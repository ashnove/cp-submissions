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
ll const maxn = 3e5+1;

void solve()
{      
      ll n; cin >> n;
      string s; cin >> s;
      ll tot = 30000000000;
      if(n==1){

            if(s[0]=='1') cout << tot/3 * 2 << endl;
            else cout << tot/3 << endl;
            
            return;
      }
      if(n==2){
            if(s=="11") cout << tot/3 << endl;
            else if (s=="10") cout << tot/3 << endl;
            else if(s=="01") cout << tot/3 - 1 << endl;
            else if(s=="00") cout << 0 << endl;
            return;
       }

      bool ok = 0;
      string p = "";
      if( s.substr(0,3)=="110" )ok=1, p = "110";
      else if( s.substr(0,3)=="101" )ok=1, p = "101";
      else if( s.substr(0,3)=="011" )ok=1, p = "011";
 
      if(!ok){
            cout << 0 << endl;
            return;
      }
      ok = 1;
      for(ll i = 0; i<=n-3; i+=3){
            if( s[i]==p[0] && s[i+1]==p[1] && s[i+2]==p[2] ) continue;
            else ok = 0;
      }
      if(!ok){
            cout << 0 << endl;
            return;
      }
      
      
      tot -= (n-3);

      if(p=="101") tot--;
      if(p=="011") tot-=2;
      ll ans = tot/3;
      ok = 1;
      ll rem = n%3;
      ll len = n/3; len*=3;
      if(rem){
            f(i,0,rem){
                  if(s[len+i]!=p[i])ok=0;
            }
      }
      if(!ok) ans = 0;

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