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
ll const inf = 1e18;
ll const maxn = 2e5+1;
class The{
public:
      ll up, down;
};
vector<ll> adj[maxn];
ll vis[maxn], vis2[maxn], degree[maxn], c[maxn], cnt = 0,k;
vector<ll> testing;
void dfs(ll x){
      vis[x] = 1;
      for(ll i=0; i<k; i++)
            if(c[i]==x)
                  vis2[x] = 1;
      cnt++;
      testing.pb(x);
      ll cur = 0;
      for(auto e : adj[x]){
            if(!vis[e]){
                  cur++;
                  dfs(e);
            }
      }
      cnt += max(0ll, cur-1);
}
void solve()
{
      string s; cin >> s;
      ll n = s.size();
      ll turn = 1;
      f(i,0,n){
            if(turn==1){
                  if(s[i]=='a')s[i]='b';
                  else s[i]='a';turn = 0;
            }
            else{
                 if(s[i]=='z')s[i]='y';
                  else s[i]='z';
                  turn = 1;
            }
      }
      cout << s << endl;
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
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     