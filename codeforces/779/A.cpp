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
      ll n; cin >> n;

      ll a[n]; f(i,0,n) cin >> a[i];
      ll b[n]; f(i,0,n) cin >> b[i];

      ll cntA[6]={0}, cntB[6]={0};
      f(i,0,n){
            cntA[a[i]]++;
            cntB[b[i]]++;
      }
      ll ans = 0; bool ok = 1;
      for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                  if(a[i]==b[j])continue;
                  // if(a[i]==3)
                  // cout << a[i] << " " << cntA[a[i]] << endl;
                  if(cntA[a[i]] > cntB[a[i]]){
                        if(cntB[b[j]] > cntA[b[j]])
                        {
                              ans++;
                              // cout << i << " " << j << endl;
                              // swap(b[j], a[i]);
                              cntA[a[i]]--;
                              cntB[a[i]]++;
                              cntA[b[j]]++;
                              cntB[b[j]]--;
                        }
                  }

            }
      }
      sort(a,a+n);
      sort(b,b+n);
      // f(i,0,n){
      //       cout << a[i] << " ";
      // }
      // nl;
      // f(i,0,n){
      //       cout << b[i] << " ";
      // }nl;
      f(i,1,6)
            if(cntA[i]<0 || cntB[i]<0 ||cntA[i]!=cntB[i])ok = 0;
      if(ok)cout << ans << endl;
      else cout << -1 << endl;
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