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
// #define endl "\n"
#define nl cout << endl;
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(x) cerr << #x << " is " << x << endl;
#define ar vector<ll>
#define mat vector<vector<ll>>
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}
bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
            return 1;
      return 0;
}
class Pair { public: ll first, second;};
bool comp3(const Pair &a, const Pair &b) {
      if (a.F > b.F) return 1; return 0;
}
class Trips { public: ll first, second, third;};
bool comp4(const Trips &a, const Trips &b) {
      if (a.Th > b.Th) return 1; return 0;
}

ll const mod = 1e9 + 7;
ll const inf = 1e18;
ll const maxn = 5e5 + 1;



void solve()
{
      ll t = 1;
      // cin >> t;

      for (ll tt = 1; tt <= t; tt++) {
            ll n; cin >> n;

            string s; cin >> s;
            s += s;

            ll L = 0, R = 2 * n - 1;

            ll turn = 0;
            ll q; cin >> q;
            while (q--) {

                  ll T, a, b; cin >> T >> a >> b;
                  a--, b--;

                  if (T == 2) {
                        turn ^= 1;
                        if (turn)
                              L = n, R = 3 * n - 1;
                        else
                              L = 0, R = 2 * n - 1;
                  }
                  else {
                        if(turn)
                              a = L + a, b = L + b;

                        if ( (a>=0&&b<n)|| (a>=n&&b<2*n) || (a>=2*n&&b<3*n)) {

                              if (b < n || a >= 2*n) {
                                    swap(s[a], s[b]);
                                    if(b < n)
                                    swap(s[a + 2 * n], s[b + 2 * n]);
                                    if(a>=2*n)swap(s[a - 2 * n], s[b- 2 * n]);

                              }
                              else {
                                    swap(s[a], s[b]);
                              }
                        }
                        else {
                              // cout << "{" << a << " , " << b << "} " ;

                              if( a >= n && a < 2*n){
                                    char temp = s[b];
                                    s[b] = s[b - 2*n] = s[a];
                                    s[a] = temp;
                              }
                              else{
                                    char temp = s[a];
                                    s[a] = s[a + 2*n] = s[b];
                                    s[b] = temp;
                              }
                        }

                  }

                  // cout << T << " " << s.substr(0, 3*n) << endl;

            }
            if (turn)
                  L = n, R = 3 * n - 1;
            else
                  L = 0, R = 2 * n - 1;

            // cout << s << endl;
            for(ll i = L; i <= R; i++)
                  cout << s[i];
            nl;
      }
}



int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      //*
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif/**/
      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}