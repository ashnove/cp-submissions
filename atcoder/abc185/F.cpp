/*
* @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
ll const inf = 3e5+5;
 
ll st[1<<20], lazy[1<<20], arr[inf];
//treebuild
void buildTree(ll si, ll ss, ll se)
{
    if(ss == se){
        st[si] = arr[ss];
        return;
    }
 
    ll mid = (ss + se)/2;
 
    buildTree( 2*si, ss, mid );
    buildTree( 2*si+1, mid+1, se);
 
    st[si] = (st[2*si] ^ st[2*si+1]) ;
}
 
void update(ll si, ll ss, ll se, ll qs,ll qe, ll val)
{
 
    st[si] ^= lazy[si] * (se - ss + 1);
 
    if(ss!=se)
        lazy[2*si] ^= lazy[si], lazy[2*si+1] ^= lazy[si];
    lazy[si] = 0;
 
    if( se < qs || ss > qe )return;
 
    if(ss >= qs && se <= qe){
        st[si] ^= val * (se - ss + 1) ;
        if(ss!=se)
            lazy[2*si] ^= val , lazy[2*si + 1] ^= val;
        return;
    }
 
    ll mid = (ss+se)/2;
    update(2*si, ss, mid, qs, qe, val);
    update(2*si+1, mid+1, se, qs, qe, val);
 
    st[si] = (st[2*si]^st[2*si + 1]);
}
 
ll query(ll si, ll ss, ll se, ll qs, ll qe)
{   
    
    st[si] ^= (lazy[si] * (se - ss + 1));
 
    if(ss!=se)
        lazy[2*si] ^= lazy[si], lazy[2*si+1] ^= lazy[si];
    lazy[si] = 0;
 
    if( ss > qe || se < qs)
        return 0;
    if( ss >= qs && se <= qe ){
 
        return st[si];
    }
 
    ll mid = (ss + se)/2;
 
    ll l = query( 2*si, ss, mid, qs, qe );
    ll r = query( 2*si+1, mid+1, se, qs, qe);
 
    return (l^r);
}
void solve()
{
          ll n,q; cin >> n >> q;
          f(i,1,n+1) cin >> arr[i];
          buildTree(1,1,n);
       
          while(q--){
       
              ll ch;
              cin >> ch;
              switch(ch){
       
                  case 1:
                      ll l,r,x;
                      cin >> l >> x;
                      arr[l]^=x;
                      update(1,1,n,l,l,x);
                  break;
                  case 2:
                      ll y,yy; cin >> y >> yy;
                      cout << query(1,1,n,y,yy) << endl;
                  break;
              }
       
          }
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