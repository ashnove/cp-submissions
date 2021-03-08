/*
      @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define F first
#define S second
#define Th third
#define endl "\n"
#define nl cout<<endl;
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define what_is(x) cerr << #x << " is " << x << endl;
#define mat vector<vector<ll>>
mat cn(ll n, ll m) {return vector< vector<ll> >(n, vector<ll>(m));}
bool comp1(char &s1, char &s2) {return s1 > s2;}
bool comp2(const pair<ll, pair<ll, ll>> &a,  const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first ) return 1;
      if ( a.first == b.first && a.S.S > b.S.S ) return 1;
      return 0;
}
class Pair { public: ll first, second;};
bool comp3(const Pair &a, const Pair &b) {
      if (a.F > b.F) return 1;
      return 0;
}
class Trips { public: ll first, second, third;};      
bool comp4(const Trips &a, const Trips &b) {
      if (a.Th > b.Th) return 1;
      return 0;
}

ll const mod = 1e9 + 7;
ll const inf = 1e18;
ll const maxn = 2e5 + 1;

vector<ll> adj[maxn];
ll vis[maxn];
ll ed,vv;
void dfs(ll x){
      vis[x] = 1;
      vv++;
      for(auto ch : adj[x]){
            ed++;
            if(!vis[ch]){
                  dfs(ch);
            }
      }
}

void solve()
{
      ll n,k; cin >> n >> k;
      ll m = n-k+1;
      string s[m]; f(i,0,m) cin >> s[i];

      string ans[n];
      ll it = 0; char e = 'a';
      for(;it < min(n, 26ll); it++){
            string pp = "A";
            pp += e;
            e++;
            ans[it] = pp;
      }
      e = 'a';
      for(; it < n; it++){
            string pp = "B";
            pp += e;
            e++;
            ans[it] = pp;
      }

      it = 0;
      for(ll i = k-1; i < n; i++){
            if(s[it++]=="NO"){
                  ans[i] = ans[i-k+1];
            }
      }
      for(ll i = 0; i < n; i++)
            cout << ans[i] << " ";

}


int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
//*
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
      /**/
      ll tt = 1;
      // cin >> tt;
      f(testcases, 0, tt) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}