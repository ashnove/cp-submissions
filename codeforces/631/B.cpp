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



void solve()
{
      ll n,m,k; cin >> n >> m >> k;

      ll a[n][m]={0};

      map<ll,ll> r, c;
      map<ll,ll> rowtime, coltime   ;

      for(ll i = 1; i <= k; i++){
            ll p,x,ai; cin >> p >> x >> ai;
            x--;
            if(p==1){
                  rowtime[x] = i;
                  r[x]=ai;
            }else{
                  coltime[x] = i;
                  c[x]=ai;
            }
      }

      for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){

                  if(rowtime[i]== 0 && coltime[j]==0)
                        cout << 0;
                  else if(rowtime[i] > coltime[j])
                        cout << r[i];
                  else if(coltime[j] > rowtime[i])
                        cout << c[j];
                  cout << " ";
            }
            cout << endl;
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
      ll tt = 1;
      // cin >> tt;
      f(testcases, 0, tt) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}