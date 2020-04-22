#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define Fi(n) for(ll i=0;i<n;i++)
#define Fj(n) for(ll j=0;j<n;j++)
#define Fiab(a,b) for(ll i=a;i<b;i++)
#define Fjab(a,b) for(ll j=a;j<b;j++)
#define sexy ios_base::sync_with_stdio(false);cin.tie(NULL);
#define txti freopen("input.txt", "r", stdin);
#define txto freopen("output.txt", "w", stdout);
ll t,k,l,r;

bool sortmahstyle(const pair<int,int> &a,  const pair<int,int> &b) 
{ 
    if(a.first<b.first)
        return true;
        
    return false;
    
} 
ll segment(ll a[],ll n){
    
    ll cnt = 2,final_cnt = LLONG_MIN;
    ll i=2;
    while(i<n){
        
                if(a[i]== a[i-1]+a[i-2])
                        cnt++;
                
                else
                        cnt=2;
                    
                i++;
                
                if(cnt>final_cnt)
                        final_cnt = cnt;
                    
    }
    
    return final_cnt;
}


int main() {
sexy    
//txti
//txto
    
   
    ll n;
    cin>>n;
    ll seq[n];
    Fi(n) cin>>seq[i];
    
    if(n<=2){
        
            cout<<n;
            return 0;
        
    }
    
    ll ans = segment(seq,n);
    
    cout<<ans<<endl;
    
    return 0;
}