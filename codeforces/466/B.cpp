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
ll const maxn = 1e5+1;
class The{
public:
      ll up, down;
};

void solve()
{
      ll n,a,b; cin >> n >> a >> b;
      ll ans = inf, A=a , B=b;
      bool ok = 0;
      if(a*b >= 6*n){
            cout << a*b << endl << a << " " << b << endl;
            return;
      }
      else{
            if(a>b){ok=1;swap(a,b);}

            for(ll i = a; i<= ceil(sqrt(6*n)); i++){
                  ll j = (6*n + i - 1)/i;
                  if( j>=b ){
                        if(ans > i*j){
                              A = i, B = j;
                              ans = i*j;
                        }
                  }
            }     
      }
      cout << ans << endl;
      if(ok)swap(A,B);
      cout << A << " " << B << endl;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
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