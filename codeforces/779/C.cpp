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
#define what_is(x) cerr << #x << " is " << x << endl;
#define mat vector<vector<ll>>
mat cn(ll n, ll m) {return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1, char &s2) {return s1 > s2;}
bool sortmahstyle(const pair<ll, pair<ll, ll>> &a,  const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first ) return 1;
      if ( a.first == b.first && a.S.S > b.S.S ) return 1;
      return 0;
}

ll const mod = 1e9 + 7;
ll const inf = 1e17;
ll const maxn = 2e5 + 1;

void solve()
{ 
      ll n,k; cin >> n >> k;

      ll a[n],b[n];
      f(i,0,n) cin >> a[i];
      f(i,0,n) cin >> b[i];
      array<ll,2> change[n];
      f(i,0,n){
            change[i][0] = b[i]-a[i];
            change[i][1] = i;
      }
      sort(change, change+n);
      reverse(change, change+n);

      ll ans = 0, x=k-1;
      for(ll i = 0; i < k; i++)
            ans += a[change[i][1]];
      for(ll i = k; i < n; i++){
            if(change[i][0] > 0){
                  x = i;
                  ans+=a[change[i][1]];
            }
      }
      for(ll i = x+1; i < n; i++)
            ans += b[change[i][1]];
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
      ll t;
      /**/t = 1;
      /*/cin>>t;/**/
      f(testcases, 0, t) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     