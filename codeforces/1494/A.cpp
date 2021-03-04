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

bool isReg(string s){
      ll n = s.size();
      stack<ll> b;
      for(ll i = 0; i < n; i++){
            if(s[i]=='(')
                  b.push(i);
            else{
                  if(!b.empty())
                        b.pop();
                  else return 0;
            }
      }
      if(!b.empty())return 0;
      return 1;
}

void solve()
{
      string s; cin >> s;

      for(ll i = 0; i <= 7; i++){
            char A = (i&1?'(':')');
            char B = (i&(1<<1)?'(':')');
            char C = (i&(1<<2)?'(':')');
            string test = "";
            for(char e : s)
                  if(e=='A')test+=A;
                  else if(e=='B')test+=B;
                  else test+=C;

            // cout << test << endl;
            if(isReg(test)){
                  cout << "YES\n";
                  return;
            }
      }
      cout << "NO\n";
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
      /*/cin>>t;/**/
      f(testcases, 0, t) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}     