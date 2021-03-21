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


ll f[maxn];
void fact(){
      f[0]  =1;
      for(ll i = 1; i < maxn; i++)
            f[i] = (f[i-1] * i)%mod;
}

bool isValid(ll i, ll j, ll n,ll m){
      return (1<=i&&i<=n && 1<=j&&j<=m);
}

void solve()
{
      ll n; cin >> n;
      ll m; cin >> m;
      string a[n]; 
      f(i,0,n) cin >> a[i];
      map<ll,ll> cnt;   
      vector<ll> vv;
      ll o= 0, eve = 0;
      f(i,0,n){
            ll sum = 0;
            f(j,0,m) sum += a[i][j]-'0';
            vv.pb(sum);
            // cout << sum << endl;
            cnt[sum]++;
            if(sum&1) o++; else eve++;
      }
      ll ans = 0;
      for(ll i = 0; i < n-1; i++){
            // cout <<  cnt[vv[i]] << endl;
            // cnt[vv[i]]--;
            if(vv[i]&1)o--; else eve--;
            if(vv[i]&1)
                  ans += eve;
            else ans += o;

      }
      cout << ans << endl;
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

      // fact();
      ll tt = 1;
      // cin >> tt;
      f(testcases, 0, tt) {
            // cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}