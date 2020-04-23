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

int main() {
sexy    
//txti
//txto
        ll n,a,b,c,d;
        cin>>t;
        while(t--){
            
            
            cin>>n>>a>>b>>c>>d;
            
            if(   (a-b)*n > c+d   ||     (a+b)*n < c-d    )
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    

    
    return 0;
}