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

ll t,n,k,x,y;

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
    
    cin>>t;
    while(t--){
    
            cin>>n;
            ll esum=0,osum=0;
            
            if(n/2 & 1){
                cout<<"NO\n";
                continue;
            }
            else{
                cout<<"YES\n";    
               ll esum = n/2 * (n/2 + 1);
               ll xx = n/2 -1;
               ll osum = xx*xx;
               for(ll i=2;i<=n;i+=2)
                   cout<<i<<" ";
               for(ll i=1;i<n-2;i+=2)
                   cout<<i<<" ";
               cout<<esum - osum<<endl;
               
            }
    }
    
    
    return 0;
}