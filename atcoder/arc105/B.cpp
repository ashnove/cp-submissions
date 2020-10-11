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

#define mat vector<vector<ll>>
mat cn(ll n, ll m)
     {return vector< vector<ll> >(n, vector<ll>(m));}

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
ll const inf = 1e18;
ll const maxn = 1e6+1;

void solve()
{    
     ll n; cin >> n;
     ll a[n]; 
     map<ll,ll> cnt;

     f(i,0,n){
          cin >> a[i];
          ++cnt[a[i]];
     }

     while(cnt.size()>1){

          ll MAX = cnt.rbegin()->F;
          ll MIN = cnt.begin()->F;

          cnt.erase(MAX);
          cnt[MAX-MIN]=1;
     }
     cout << cnt.begin()->F << endl;
     
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








