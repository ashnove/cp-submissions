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
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 5e5+1;

void solve()
{      
      
      string s; cin >> s;
      ll n = s.size();
      ll m; cin >> m;
      ll a[m]; f(i,0,m) cin >> a[i];

      sort(s.begin(), s.end());
      reverse(s.begin(), s.end());
      map<ll,ll> acnt;
      for(char e : s) ++acnt[e];
      char p = 'z';

      ll done = m;
      char ans[m];
      while(done){
            ll sub = 0;
            char cur;
            ll zcnt = 0;
            for(ll i = 0; i < m; i++)
                  if(a[i]==0)zcnt++, a[i]=-1;
            
            for(char i = p; i>='a'; i--)
                  if(acnt[i] >= zcnt){
                        cur = i;
                        p = cur - 1;
                        break;
                  }
            for(ll i = 0; i < m; i++ ){
                  if(a[i]==-1){
                        a[i]=-2;
                        ans[i]=cur;
                        done--;
                        for(ll j = 0; j < m; j++)
                              if(a[j] > 0)
                                    a[j]-=abs(i-j);
                  }
            }            
      }
      for(char e : ans)
            cout << e;
      nl;

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
          /*/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}     