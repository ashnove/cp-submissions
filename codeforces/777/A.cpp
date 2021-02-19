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
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll, pair<ll,ll>> &a,  const pair<ll, pair<ll,ll>> &b){ 
    if(a.first > b.first ) return 1;
    if( a.first==b.first && a.S.S > b.S.S ) return 1;
    return 0;
}

ll const mod = 1e9+7;
ll const inf = 1e16;
ll const maxn = 2e5+1;
void solve()
{
      ll n; cin >> n;
      ll x; cin >> x;

      n%=6; ll y;
      if(n==0){
            y = (x==0?1:(x==1)?2:3);
      }
      if(n==1){
            y = (x==0?2:(x==1)?1:3);
      }
      if(n==2){
            y = (x==0?2:(x==1)?3:1);
      }
      if(n==3){
            y = (x==0?3:(x==1)?2:1);
      }
      if(n==4){
            y = (x==0?3:(x==1)?1:2);
      }
      if(n==5){
            y = (x==0?1:(x==1)?3:2);
      }
      cout << y-1 << endl;

}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
            ll t;
            /**/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}          