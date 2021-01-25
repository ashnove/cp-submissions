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
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}
//me19U10584
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 5e5+1;

void solve()
{      
      
      ll a,b,k; cin >> a >> b >> k;

      ll boy[k];
      f(i,0,k) cin >> boy[i];
      ll gal[k];
      f(i,0,k) cin >> gal[i];

      map< pair<ll,ll> ,ll > pcnt;
      map< ll, ll > boycnt;
      map< ll, ll > galcnt;

      pcnt[{boy[0], gal[0]}]++;
      boycnt[boy[0]]++;
      galcnt[gal[0]]++;
      ll ans = 0;
      for(ll i = 1; i<k; i++){

            ll prevB = boycnt[boy[i]];
            ll prevG = galcnt[gal[i]];
            ll prevP = pcnt[{boy[i], gal[i]}];

            ll poss = prevB + prevG - 2*prevP;
            poss = i-poss;
            ans += poss;
            pcnt[{boy[i], gal[i]}]++;
            boycnt[boy[i]]++;
            galcnt[gal[i]]++;
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
          /*/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}     