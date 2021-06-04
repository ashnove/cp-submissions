/*
* @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define Th third
#define nl cout << endl;
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(x) cerr << #x << " is " << x << endl;

using lld = long double;
using ll = long long int;
using ar = vector<ll>;
using mat = vector<vector<ll>>;
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}

ll const MOD = 1e9 + 7;
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0;}
template<class T> inline void add(T &a, T b) { a += b; a >= MOD ? a - MOD : a; }
template<class T> inline void sub(T &a, T b) { a -= b; a < 0 ? a + MOD : a; }
template<class T> inline void mul(T &a, T b) {return (a * b) % MOD; }
template<class T> void remDup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), end(v)); }

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

void readArray(ll a[], int n) {
      for (ll i = 0; i < n ; i++)
            cin >> a[i];
}

ll const inf = 1e15;
ll const mod = 1e9 + 7;
ll const maxn = 5e5 + 1;


void solve()
{
      ll t = 1;
      cin >> t;
      for (ll tt = 1; tt <= t; tt++) {

            string s; cin >> s;

            ll n = s.size();
            ll cur = 0;
            ll ans = 0;
            ll prevSeg = 0;
            ll prevEnd = -1;
            char turn = '2';
            // if(s[0] == '1') turn = '0'; else turn = '1';

            for (ll i = 0; i < n; i++) {


                  if(s[i] != '?' && turn!='2' && turn != s[i]){ 
                        // cout << i << ' ';
                        ans += prevSeg * (prevSeg - 1)/2;
                        // cout << prevSeg << endl;
                        prevSeg = 0;
                        prevEnd = s[i] - '0';
                        i--;
                        // if(s[i] == '1') turn = '0'; else turn = '1';
                        turn = '2';
                        continue;
                  }
                  if(s[i] != '?'){
                        // cout << i << " ";
                        prevSeg++;

                        if(s[i] == '1') turn = '0'; else turn = '1';
                        // cout << turn << " ";
                        prevEnd = s[i] - '0';
                        // cout << prevEnd << " ";
                        continue;
                  }
                  
                  ll qmark = 0;
                  while (i < n && s[i] == '?')
                        qmark++, i++;

                  // cur = prevEnd + qmark;
                  // cout <<  qmark << endl;

                  if (i < n) {
                        ll rr = s[i] - '0';
                        // cout << i << " ";
                        if(prevEnd == -1){
                              prevSeg += qmark; i--;
                        }
                        else if (prevEnd == rr) {
                              if (qmark & 1){
                                    prevSeg = prevSeg + qmark;i--;
                              }
                              else {

                                    ll temp = prevSeg + qmark;
                                    ans += temp * (temp - 1) / 2;
                                    ans -= (qmark*(qmark - 1)/2);
                                    prevSeg = qmark;
                                    i--;
                              }
                        }
                        else{
                              if ( (qmark % 2) == 0){
                                    prevSeg = prevSeg + qmark; i--;
                              }
                              else {

                                    ll temp = prevSeg + qmark;
                                    ans += temp * (temp - 1) / 2;
                                    ans -= (qmark*(qmark - 1)/2);
                                    
                                    prevSeg = qmark;

                                    i--;
                              }

                        }

                        turn = '2';

                  }
                  else{
                        prevSeg += qmark;
                        // ans += prevSeg * (prevSeg - 1)/2;
                  }


                  // cout << i << " " << ans << endl;
                  prevEnd = s[i] - '0';
                                    // cout << prevSeg << " ";
            }
            // cout << prevSeg << endl;
            ans += (prevSeg*(prevSeg - 1))/2;
            cout << ans + n << endl;
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

