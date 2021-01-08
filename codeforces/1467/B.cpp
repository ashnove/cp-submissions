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
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b){ 
    if(a.first < b.first ) return 1;
    if( a.first==b.first && a.S != b.second ) return 1;
    return 0;
}
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 5e5+1;


void solve()
{      
      
      ll n; cin >> n;
      ll a[n]; f(i,0,n) cin >> a[i];
      ll hill=0, vall = 0;
      bool ishill[n];
      bool isvall[n];
      f(i,0,n) isvall[i]=0, ishill[i]=0;
      for(ll i = 1; i<n-1; i++){

            if( a[i+1]>a[i] && a[i]<a[i-1] )
                  vall++, isvall[i]=1;
            else if( a[i]>a[i+1] && a[i]>a[i-1] )
                  hill++, ishill[i]=1;

      }
      ll incRight[n],incLeft[n], decRight[n],decLeft[n];
      incLeft[0]=decLeft[0]=0;
      for(ll i = 1; i<n; i++){
            if(a[i]<a[i-1])
                  incLeft[i]=incLeft[i-1];
            else
                  incLeft[i]=i;
            if(a[i]>a[i-1])
                  decLeft[i]=decLeft[i-1];
            else
                  decLeft[i]=i;

      }
      incRight[n-1]=decRight[n-1] = n-1;
      for(ll i = n-2; i>=0; i--){
            if( a[i+1] > a[i] )
                  incRight[i]=incRight[i+1];
            else  incRight[i]=i;

            if( a[i+1] < a[i])
                  decRight[i]=decRight[i+1];
            else decRight[i]=i;
      }

      ll tot = hill + vall;
      ll ans = hill+vall;
      for(ll i = 1; i<n-1; i++){
            if(ishill[i]==0 && isvall[i]==0)continue;

            if( ishill[i] && isvall[i+1] && isvall[i-1]){
                  ans = min(ans, tot-3);
            }
            if( isvall[i] && ishill[i+1] && ishill[i-1])
                  ans = min(ans, tot -3);
            // vall --> hill --> nothing
            if( (isvall[i-1] && ishill[i]) && a[i-1] >= a[i+1]){
                  ans = min(ans, tot-2);
            }
            if( (isvall[i-1] && ishill[i]) && a[i-1] < a[i+1] && decRight[i+1]==i+1){
                  ans = min(ans, tot-2);
            }
            if( (isvall[i-1] && ishill[i]) && a[i-1] < a[i+1] && decRight[i+1]!=i+1){
                  ans = min(ans, tot-1);
            }
            // nothing --> hill --> valley
             if((ishill[i] && isvall[i+1]) && a[i+1] >= a[i-1] ){
                  ans  = min(ans, tot - 2);
            }
             if((ishill[i] && isvall[i+1]) && a[i+1] < a[i-1] && decLeft[i-1]==i-1){
                  ans  = min(ans, tot - 2);
            }
            if((ishill[i] && isvall[i+1]) && a[i+1] < a[i-1] && decLeft[i-1]!=i-1){
                  ans  = min(ans, tot - 1);
            }
            // hill --> valley --> nothing
             if( (ishill[i-1] && isvall[i]) && a[i+1] >= a[i-1] )
                  ans = min(ans, tot- 2);
             if((isvall[i] && ishill[i-1]) && a[i-1] > a[i+1] && incRight[i+1]==i+1){
                  ans = min(ans, tot- 2);
            }
            if((isvall[i] && ishill[i-1]) && a[i-1] > a[i+1] && incRight[i+1]!=i+1){
                  ans = min(ans, tot- 1);
            }
            // nothing --> valley--> hill
             if( (ishill[i+1] && isvall[i]) && a[i-1] >= a[i+1])
                  ans = min(ans, tot- 2);
             if((isvall[i] && ishill[i+1]) && a[i-1] < a[i+1] && incLeft[i-1]==i-1){
                  ans = min(ans, tot- 2);
            }
            if((isvall[i] && ishill[i+1]) && a[i-1] < a[i+1] && incLeft[i-1]!=i-1){
                  ans = min(ans, tot- 1);
            }
             if(ishill[i] || isvall[i]) ans =min(tot-1, ans);


      }
      cout << max(0ll,ans) << endl;
      
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
            /*/t=1;
            /*/cin>>t;/**/
            f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
            } 
      return 0;
}     