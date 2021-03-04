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

bool isRange(ll val, ll x, ll y)
{
      return ( val>=x && val<=y );
}
void solve()
{
      ll n; cin >> n;
      ll U,R,D,L; cin >> U >> R >> D >> L;

      for(ll i = 0; i <= 15; i++){
            ll u,r,d,l;
            u = U, r=R,d=D,l=L;
            ll test[n][n]={0};
            if(i&1 && u && l){
                  test[0][0]++;
                  u--,l--;
            }else{
                  test[0][0]=-1;
            }
            if(i&(1<<1) && u && r){
                  test[0][n-1]++;
                  u--,r--;
            }else{
                  test[0][n-1]=-1;
            }
            if(i&(1<<2) && r && d){
                  test[n-1][n-1]++;
                  r--,d--;
            }else{
                  test[n-1][n-1]=-1;
            }
            if(i&(1<<3) && d && l){
                  test[n-1][0]++;
                  d--,l--;
            }else{
                  test[n-1][0]=-1;
            }
            ll pp = max({u,r,l,d});
            for(ll p = 0; p<=n-1; p++){
                  if(u>0&&test[0][p]==0)
                        test[0][p]++, u--;
            }
            for(ll p = 0; p<=n-1; p++){
                  if(r>0&&test[p][n-1]==0)
                        test[p][n-1]++, r--;
            }
            for(ll p = 0; p<=n-1; p++){
                  if(d>0&&test[n-1][p]==0)
                        test[n-1][p]++, d--;
            }
            for(ll p = 0; p<=n-1; p++){
                  if(l>0&&test[p][0]==0)
                        test[p][0]++, l--;
            }
            if(pp<=n-2){
                  // cout << i << endl;
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