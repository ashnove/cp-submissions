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

ll const mod = 1e9 + 7;
ll const inf = 1e17;
ll const maxn = 2e5 + 1;

class Pair{ public: ll first, second;};
bool comp3(const Pair &a, const Pair &b){
      if(a.F > b.F) return 1;
      return 0;
}
class Trips{ public: ll first, second, third;};
bool comp4(const Trips &a, const Trips &b){
      if(a.Th > b.Th) return 1;
      return 0;
}
void solve()
{
      ll a,b,w; cin >> a >> b >> w;
      w*=1000;
      ll last = -1;
      bool ok  = 1;
      if(a > w)ok = 0;
      ll cnt = (w)/a;
      if(w%a)
            last = a + ((w%a+cnt-1)/cnt);

      if(last != -1 && (last > b|| last < a )){
            ok = 0;
      }
      // cout << ok << endl;
      ll maxx, minn;
      maxx = cnt;

      last = -1;
      cnt = (w+b-1)/b;
      if(w%b)
            last = w%b;
      minn = cnt;
      // cout << cnt << endl;
      //  if(last != -1 && (last > b|| last < a )){
      //       ok = 0;
      // }

      if(ok)
            cout << minn << " " << maxx << endl;
      else
            cout << "UNSATISFIABLE\n";

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
      ll t;
      t = 1;
      // cin >> t; 
      f(testcases, 0, t) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}