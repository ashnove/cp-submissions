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
ll const maxn = 5e5+1;
class edge{
public:
      ll a,b,w;
};

ll face(string s){
      if(s=="Tetrahedron")return 4;
      if(s=="Cube") return 6;
      if(s=="Octahedron") return 8;
      if(s=="Dodecahedron") return 12;
      return 20;
}

bool ok(ll a,ll b, ll c){
      return ( (a+b>c&&b+c>a&&c+a>b?1:0) );
}
void solve()
{
      ll n; cin >> n;
      ll a[n]; f(i,0,n) cin >> a[i];

      sort(a,a+n);
      ll ans = 0; 
      for(ll i = 0; i < n; i++){
            for(ll j = i+1; j < n; j++){

                  ll sum = a[i]+a[j];
                  ll low = j+1, high = n-1;
                  ll res = j;
                  while(low <= high){
                        ll mid = (low + high)/2;

                        if(a[mid] >= sum)
                              high = mid - 1;
                        else{
                              res = mid;
                              low = mid + 1;
                        }
                  }
                  ans += (res - j);
            }
      }
      cout << ans << endl;
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