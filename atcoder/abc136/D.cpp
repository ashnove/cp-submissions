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
ll const mod = 998244353;
ll const inf = 1e6+1;
ll const maxn = 5e5+1;

void solve()
{
      string s;cin >>s;
      ll n = s.size();

      ll nearLeft[n], nearRight[n];
      nearLeft[n-1] = n-1, nearRight[0]=0;
      for(ll i = n-2; i>=0; i--){
            if(s[i]!='L') nearLeft[i]=nearLeft[i+1];
            else nearLeft[i]=i;
      }
      for(ll i = 1; i<n; i++){
            if(s[i]!='R') nearRight[i]=nearRight[i-1];
            else nearRight[i]=i;
      }     

      ll ans[n]={0};
      for(ll i = 1; i<n;i++)
            if(s[i]=='L'){
                  ll travel = i-nearRight[i];
                  if(travel&1)ans[nearRight[i]+1]++;
                  else ans[nearRight[i]]++;
            }

      for(ll i = 0; i<n-1; i++)
            if(s[i]=='R'){
                  ll travel = nearLeft[i]-i;
                  if(travel&1)ans[nearLeft[i]-1]++;
                  else ans[nearLeft[i]]++;
            }
      for(ll i : ans)
            cout << i << " ";
      nl;
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

/*
while(!pq.empty()){
            cout << pq.top().second << " " << pq.top().F << endl;;
            pq.pop();
      }
      */