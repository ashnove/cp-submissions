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

bool isTrue(string s, ll k){
      map<char, ll> allCnt;
      for(char e : s)
            allCnt[e]++;
      bool ok = 1;
      for(auto e : allCnt){
            if(e.S%k)ok=0;
      }
      return ok;
}

void solve()
{
      ll n,k; cin >> n >> k;
      string s; cin >> s;

      if(n%k){
            cout << -1 << endl;
            return;
      }
      map<char, ll> allCnt;
      for(char e : s)
            allCnt[e]++;
      bool ok = 1;
      for(auto e : allCnt){
            if(e.S%k)ok=0;
      }
      if(ok){
            cout << s << endl;
            return;
      }
      map<char, ll> prefHash;

      ll changeAt = -1; char changeTo;
      ll finalConsume = 0;
      for(ll i = 0; i < n; i++){

            // if(s[i]=='z')continue;
            
            char ee = s[i]; ++ee;
            for(; ee <='z'; ee++){

                  ll spaceNeeded = 0;
                  for(char ch = 'a'; ch <= 'z'; ch++){
                        if(prefHash[ch]==0 && ch!=ee)continue;
                        ll c = prefHash[ch] + (ch==ee?1:0);
                        ll m = (c+k-1)/k;
                        // if(i==n-1)
                        spaceNeeded += k*m - c;
                  }
                  if(spaceNeeded <= n-i-1){
                        changeAt = i;
                        changeTo = ee;
                        finalConsume = spaceNeeded;
                        break;
                  }
            }
                  // cout << i << " " << spaceNeeded << endl;
            
            prefHash[s[i]]++;

      }
      // cout << changeAt << " ";
      if(changeAt==-1)
            cout << -1 << endl;
      else{
            string ans = "";
            for(ll i = 0; i < changeAt; i++)
                  ans += s[i];
            ans += changeTo;
            for(ll i = 0; i < (n-changeAt-1)-finalConsume; i++){
                  ans += 'a';
            }
            map<char,ll> temp;
            for(ll i = 0; i < changeAt; i++)
                  temp[s[i]]++;
            temp[changeTo]++;

            for(char ch = 'a'; ch <='z'; ch++){
                  if(temp[ch]==0)continue;
                  ll need = ((temp[ch]+k-1)/k)*k - temp[ch];
                  while(need--)
                        ans += ch;
            }
            cout << ans << endl;
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
      /*/t = 1;
      /*/cin >> t; /**/
      f(testcases, 0, t) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}