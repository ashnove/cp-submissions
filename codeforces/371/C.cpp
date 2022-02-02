#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define Th third
#define nl cout << endl;
#define endl "\n";
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(dp2) cerr << #dp2 << " is " << dp2 << endl;

using lld = long double;
using ll = long long int;
using ar = vector<ll>;
using mat = vector<vector<ll>>;
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}

ll const MOD = 1000000007;
bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
            return 1;
      return 0;
}
ll const inf = 1e18;
ll const maxn = 1e9 + 1;
void solve() {

      int tt1 = 1;
      // cin >> tt1;
      for (int tt = 1; tt <= tt1; tt++) {
            string s; cin >> s;
            ll n = s.size();
            ll brd_cnt, sg_cnt, chz_cnt;
            cin >> brd_cnt >> sg_cnt >> chz_cnt;
            ll brd_price, sg_price, chz_price;
            cin >> brd_price >> sg_price >> chz_price;
            ll r; cin >> r;
            ll b,sg,c; b=sg=c=0;
            for(char e : s){
                  if(e == 'B') b++;
                  else if(e == 'C') c++;
                  else sg++;
            }
            ll low = 1, high = 1e15;
            ll ans = 0;
            while(low <= high){
                  ll mid = low + (high - low) / 2;
                  
                  ll sg_req = max(0ll, mid*sg - sg_cnt);
                  ll b_req = max(0ll, mid*b - brd_cnt);
                  ll c_req = max(0ll, mid*c - chz_cnt);
                  ll cost = sg_req*sg_price + chz_price*c_req + brd_price*b_req;
                  if(cost <= r){
                        ans = mid;
                        low = mid + 1;
                  }
                  else high = mid - 1;
            }  
            cout << ans << endl;
      }
}     

int main() {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      solve();
      // cout << "Case #" <<tt<<": ";
      return 0;
}
