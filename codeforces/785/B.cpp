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

void solve()
{
      ll n; cin >> n;

      vector<pair<ll,ll>> chess, prog;
      ll chessMin = inf, chessMax = 0;
      for(ll i = 0; i < n; i++){
            ll L,R; cin >> L >> R;
            chess.pb({L,R});
            chessMin = min(chessMin, R);  
            chessMax = max(chessMax, L);
      }     
      ll m; cin >> m;
      ll progMax = 0, progMin = inf;
      ll ans = 0;
      for(ll i = 0; i < m; i++){
            ll L,R; cin >> L >> R;
            prog.pb({L,R});
            progMax = max(progMax, L); 
            progMin = min(progMin, R);
            // if(L>=chessMin)  
            // ans = max(ans, max(0ll, L - chessMin));
      }     
      // ans = max(0ll ,)

      if(progMax >= chessMin) ans = progMax - chessMin;
      if(chessMax>=progMin) ans = max(ans,chessMax - progMin);

      
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