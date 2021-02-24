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
ll const maxn = 2e5+1;
class edge{
public:
      ll a,b,w;
};

vector<edge> adj;

void solve()
{
      
      string s,t; cin >> s >> t;

      ll n = s.size(), m = t.size();
      string ans = s;
      ll noo = 0;
      for(ll i = n-1; i>=0; i--){
            if( n-i >= m ){
                  ll it = i;
                  for(ll j = 0; j < m; j++, it++){
                        if( s[it]=='?' || s[it]==t[j] )
                              ans[it]=t[j];
                        if(s[it] != '?' && s[it] != t[j]){
                              ans = s;
                              goto nextone;
                        }
                  }
            }
            else continue;
            break;
            nextone:
            noo++;
            ;
      }
      if(n-m+1 == noo){
            cout << "UNRESTORABLE";
            return;
      }
      for(auto e : ans){
            if(e=='?')cout << 'a' ;
            else cout << e;
      }
      nl;
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