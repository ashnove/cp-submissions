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
     
     ll a[5]={0}; ll sum = 0;
     f(i,0,4){
          cin >> a[i+1];
          sum+=a[i+1];
     } 
          bool ok = 0;

     f(i,0,5)
          f(j,0,5)
               f(k,0,5)
                    f(l,0,5)
                    {
                         ll cur = a[i]+a[j]+a[k]+a[l];
                         if(sum-cur==cur)
                              ok=1;
                    }

     cout << (ok?"Yes":"No");
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








