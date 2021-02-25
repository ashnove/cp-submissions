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

bool isSub(string s, string t){
      ll n = s.size();
      ll m = t.size();

      if(m>n)return 0;

      ll cnt = 0;
      for(ll i = 0, j = 0; i<m; i++){
            while(j < n && s[j]!=t[i])
                  j++;
            if(j<n) cnt++, j++;
      }
      return cnt==m;
}
void solve()
{
      string s; cin >> s;
      string t; cin >> t;

      ll n = s.size(), m = t.size();

      ll a[n]; f(i,0,n){ cin >> a[i]; a[i]--; }

      ll low = 0, high = n-1;
      ll ans = 0;
      while(low <= high){
            ll mid = (low + high)/2;

            string cur="", c=s;
            for(ll i = 0; i <= mid; i++)
                  c[a[i]]='*';
            for(ll i = 0; i < n; i++)
                  if(c[i]!='*')cur+=c[i];

            if(isSub(c,t)){
                  ans = mid+1;
                  low = mid + 1;
            }
            else high = mid - 1;

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
      /*/cin>>t;/**/
      f(testcases, 0, t) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     