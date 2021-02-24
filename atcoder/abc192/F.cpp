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
ll const inf = 1e18;
ll const maxn = 2e5+1;
class edge{
public:
      ll a,b,w;
};

vector<edge> adj;

void solve()
{
      ll n,x; cin >> n >> x;
      ll a[n];
      for(ll i = 0; i < n; i++)
            cin >> a[i];

      ll dp[n][n+1][n];
      f(i,0,n)f(j,0,n+1)f(k,0,n) dp[i][j][k] = -1;
      f(i,0,n) dp[i][0][0] = 0;

      for(ll i = 0; i < n; i++){


            for(ll j = 0; j < n; j++){

                  for(ll cnt = i+1; cnt>0; cnt--){

                        for(ll rem = 0; rem <= i; rem++){

                              if(dp[i][cnt-1][rem]!=-1){
                                    ll sum = dp[i][cnt-1][rem] + a[j];
                                    dp[i][cnt][ sum%(i+1) ] = max(dp[i][cnt][ sum%(i+1) ] , sum);
                              }

                        }

                  }

            }

      }

      ll res = x;
      for(ll i = 0; i < n; i++){

            if(dp[i][i+1][ x % (i+1) ] != -1)
                  res = min(res, (x - dp[i][i+1][ x % (i+1) ])/(i+1));
      }
      cout << res << endl;
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