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
struct custom_hash {
      static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
      }
      size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
      }
};
ll const mod = 1e9 + 7;
ll const inf = 1e17;
ll const maxn = 2e5 + 1;

void solve()
{
      ll n; cin >> n;
      string s; cin >> s;

      ll west[n]={0}, east[n]={0};
      for(ll i = 0; i < n; i++)
            if(s[i]=='E')east[i]++; else west[i]++;
      for(ll i = 1; i < n; i++)
            east[i]+=east[i-1], west[i]+=west[i-1];

      ll ans = inf;
      for(ll i = 0; i < n; i++){
            ll cur = 0;
            if(i-1>=0)
                  cur+= west[i-1];
            if(i+1<n)
                  cur+= east[n-1]-east[i];
            ans = min(ans, cur);
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