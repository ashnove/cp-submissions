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
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mod 100000007
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
//me
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 2e5+1;

vector<ll> st(1<<19), arr(maxn);
void buildTree(ll si, ll ss, ll se)
{
    if(ss == se){
        st[si] = arr[ss];
        return;
    }
 
    ll mid = (ss + se)/2;
 
    buildTree( 2*si, ss, mid );
    buildTree( 2*si+1, mid+1, se);
 
    st[si] = max( st[2*si], st[2*si+1] );
}
 
ll query(ll si, ll ss, ll se, ll qs, ll qe)
{
    if( ss > qe || se < qs)
        return 0;
    if( ss >= qs && se <= qe )
        return st[si];
 
    ll mid = (ss + se)/2;
 
    ll l = query( 2*si, ss, mid, qs, qe );
    ll r = query( 2*si+1, mid+1, se, qs, qe);
 
    return max(l,r);
}
void solve()
{      
      ll n,q; cin >> n >> q;

      ll covered[n+2]={0};
      vector< pair<ll,ll> > vv;
      f(i,0,q){
            ll x,y; cin >> x >> y;
            vv.pb({x,y});
            covered[x]++;
            covered[y+1]--;
      }
      f(i,2,n+1)
            covered[i]+=covered[i-1];
      ll tot = 0;
      f(i,0,q){
            ll a = vv[i].F, b = vv[i].S;

            for(ll p = a; p <= b; p++){
                  covered[p]--;
            }
            ll totpres = 0;
            f(j,1,n+1)
                  if(covered[j])totpres++;
            ll hash[n+1]={0};
            f(j,1,n+1)
                  if(covered[j]==1)hash[j]=1;
            f(j,2,n+1) hash[j]+=hash[j-1];

            f(j, i+1, q){
                  tot = max(tot, totpres -(hash[vv[j].S] - hash[vv[j].F-1]));
            }
            for(ll p = a; p <= b; p++){
                  covered[p]++;
            }

      }
      cout << tot << endl;
}

int main() {
Knucklehead 
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
 
 
    return 0;
}     