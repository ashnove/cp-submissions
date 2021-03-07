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
bool comp1(char &s1, char &s2) {return s1 > s2;}
bool comp2(const pair<ll, pair<ll, ll>> &a,  const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first ) return 1;
      if ( a.first == b.first && a.S.S > b.S.S ) return 1;
      return 0;
}

ll const mod = 1e9 + 7;
ll const inf = 1e17;
ll const maxn = 2e5 + 1;


void solve()
{

      ll n, m; cin >> n >> m;
      vector<ll>a(n);
      for (auto &ai : a) 
            cin >> ai
      ;
      vector<ll> pos[n + 1];
      for (ll i = 0; i <= n; i++) 
            pos[i].pb(0);
      for (ll i = 0; i < n; i++) 
            pos[a[i]].pb(i + 1);
      for (ll i = 0; i <= n; i++) 
            pos[i].pb(n + 1);
      
      for (ll i = 0; i <= n; i++) {
            for (ll j = 1; j < pos[i].size(); j++)
                  if (pos[i][j] - pos[i][j - 1] > m) {
                        cout << i << endl;
                        return;
                  }
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
      ll t;
      /**/t = 1;
      /*/cin >> t; /**/
      f(testcases, 0, t) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}