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

ll const inf = 1e18;
ll const maxn = 5e5 + 1;

vector<int> adj[maxn], depth[maxn];
vector<int> in(2 * maxn), out(2 * maxn), level(maxn);

ll timer = 1;
void dfs(int from, int d, int par = -1) {

      in[from] = timer++;
      level[from] = d;
      depth[d].pb(from);
      for (int to : adj[from]) {
            if (to != par)
                  dfs(to, d + 1, from);
      }
      out[from] = timer++;
}



void solve()
{
      ll t = 1;
      // cin >> t;
      for (ll tt = 1; tt <= t; tt++) {
            int n, q; cin >> n >> q;

            vector<int> a(n + 1);
            for (int i = 2; i <= n; i++) {
                  cin >> a[i];
                  adj[a[i]].pb(i);
            }
            string s; cin >> s;

            dfs(1, 1);

            // vector<vector<int>> hash[n + 1];
            // memset(hash, 0 , sizeof hash);

            // for(int i = 1; i <= n; i++){

            //       for(int j = 0; j < depth[i].size(); j++){
            //             hash[i][depth[i][j] - 'a']++;
            //       }
            // }  
            map<pair<int,int>,int> used;
            while(q--){

                  int v, h; cin >> v >> h;

                  if(level[v] > h || depth[h].size() == 0)
                        cout << "Yes\n";
                  else{
                        int done = used[{v, h}];
                        if(done != 0){
                              if(done == 1) cout << "Yes\n";
                              else cout << "No\n";
                              continue;
                        }
                        int left = -1, right = -1;

                        int low = 0, high = (int)depth[h].size() - 1;
                        while(low <= high){

                              int mid = (low + high)/2;

                              int cur = depth[h][mid];
                              if(in[cur] >= in[v] && out[cur] <= out[v]){
                                    left = mid;
                                    high = mid - 1;
                              }
                              else if( in[cur] >= in[v] )
                                    high = mid - 1;
                              else low = mid + 1;
                        }
                        low = 0, high = depth[h].size() - 1;
                        while(low <= high){

                              int mid = (low + high)/2;

                              int cur = depth[h][mid];
                              if(in[cur] >= in[v] && out[cur] <= out[v]){
                                    right = mid;
                                    low = mid + 1;
                              }
                              else if( in[cur] >= in[v] )
                                    high = mid - 1;
                              else low = mid + 1;
                        }

                        int odd = 0;
                        if(left == -1 || right == -1){
                              cout << "Yes\n";
                              used[{v, h}] = 1;
                              continue;
                        }
                        vector<int> hash(26);
                        for(int i = left; i<=right; i++){

                              int cur = s[depth[h][i]-1] - 'a';
                              hash[cur]++;

                        }
                        for(int i = 0; i < 26; i++){
                              if(hash[i] & 1) odd++;
                              // if(i == 2 || i == 3)
                              //       cout << hash[i] << " ";
                        }
                        // nl;
                        // cout << left << " " << right << endl;

                        if(odd < 2){
                              cout << "Yes\n";
                              used[{v, h}] = 1;
                        }
                        else {
                        
                              cout << "No\n";
                              used[{v, h}] = -1;
                        }
                  }


            }


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