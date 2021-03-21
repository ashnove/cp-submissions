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

      ll a[n][n], copy[n][n];
      f(i,0,n) f(j,0,n) cin >> a[i][j];

      for(ll j = 0; j < n; j++){
            for(ll i = n-1; i >= 0; i--){
                  copy[n-i-1][j] = a[i][j];
            }
      }     

      vector<ll> b;
      for(ll i = 0; i< n; i++){
            ll cur = inf;
            for(ll j = 0; j < n; j++)
                  cur = min(cur, a[i][j]);

            for(ll j = 0; j < n; j++)
                  a[i][j]-=cur;

            b.pb(cur);

      }

      // for(ll i = 0; i < n; i++){
      //       for(ll j = 0; j < n; j++)
      //             cout << a[i][j] << " ";
      //       nl;
      // }nl;
      bool ok  = 1;
      vector<ll> lar;
      for(ll j = 0; j < n; j++){
            ll cur = 0;
            for(ll i = 0; i < n; i++){
                  cur = max(cur,a[i][j]);
            }
            lar.pb(cur);
      }
      ll ch1[n][n], ch2[n][n];
      memset(ch1, 0, sizeof ch1);
      memset(ch2, 0, sizeof ch2);
      for(ll i = 0; i < n; i++){

            
                  set<ll> s;
                  for(ll j = 0; j < n; j++){

                        ll ch = lar[j] - a[i][j] ;
                        // cout << lar[j] << " - " << i << " " << j << endl;
                        if(b[i] >= ch){
                              b[i]-=ch;
                              a[i][j]+=ch;
                              ch1[i][j] += ch;
                        }else{
                              ok = 0;
                        }
                  }

                  
            
      }
      vector<ll> b2;
      for(ll i = 0; i< n; i++){
            ll cur = inf;
            for(ll j = 0; j < n; j++)
                  cur = min(cur, copy[i][j]);

            for(ll j = 0; j < n; j++)
                  copy[i][j]-=cur;

            b2.pb(cur);

      }
      bool ok2  = 1;
      vector<ll> lar2;
      for(ll j = 0; j < n; j++){
            ll cur = 0;
            for(ll i = 0; i < n; i++){
                  cur = max(cur,copy[i][j]);
            }
            lar2.pb(cur);
      }

      for(ll i = 0; i < n; i++){

            
                  set<ll> s;
                  for(ll j = 0; j < n; j++){

                        ll ch = lar2[j] - copy[i][j] ;
                        if(b2[i] >= ch){
                              b2[i]-=ch;
                              copy[i][j]+=ch;
                              ch2[i][j] += ch;
                        }else{
                              ok = 0;
                        }
                  }                  
            
      }

      // for(ll i = 0; i < n; i++){
      //       for(ll j = 0; j < n; j++)
      //             cout << a[i][j] << " ";
      //       nl;
      // }

      for(ll i = 1; i < n; i++){
            for(ll j = 0; j < n; j++)
                        if(copy[0][j] != copy[i][j]) ok2 = 0;
      }
      for(ll i = 1; i < n; i++){
            for(ll j = 0; j < n; j++)
                        if(a[0][j] != a[i][j]) ok = 0;
      }

      for(ll i = 0; i < n; i++){
            for(ll j = 1; j < n; j++)
                        if(ch1[i][j] != ch1[i][j-1]) ok = 0;
      }
      for(ll i = 0; i < n; i++){
            for(ll j = 1; j < n; j++)
                        if(ch2[i][j] != ch2[i][j-1]) ok2 = 0;
      }
      if(ok){
            cout << "Yes\n";
            for(auto e : b)
                  cout << e << " ";
            nl;
            for(auto e : a[0])
                  cout << e << " ";
            nl;
      }
      else if(ok2){
            cout << "Yes\n";
            for(auto e : b2)
                  cout << e << " ";
            nl;
            for(auto e : copy[0])
                  cout << e << " ";
            nl;
      }
      else{
            cout << "No\n";
      }
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