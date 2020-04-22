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
    
   ll n,m;
   cin>>n>>m;
   string farm[n];
   Fi(n)
            cin>>farm[i];
            
    ll ans=0;
    
    Fi(n){
        Fj(m){
            
                if(farm[i][j]=='W'){
                    
                    if(j==0){
                        if(farm[i][j+1]=='P'){
                            farm[i][j+1]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                    }
                    else if(j==m-1){
                        if(farm[i][j-1]=='P'){
                            farm[i][j-1]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                    }
                    else{
                        if(farm[i][j-1]=='P'){
                            farm[i][j-1]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                        else if(farm[i][j+1]=='P'){
                            farm[i][j+1]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                        
                    }
                    
                }
                
        }
    }
    
    
     Fj(m){
        Fi(n){
            
                if(farm[i][j]=='W'){
                    
                    if(i==0){
                        if(farm[i+1][j]=='P'){
                            farm[i+1][j]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                    }
                    else if(i==n-1){
                        if(farm[i-1][j]=='P'){
                            farm[i-1][j]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                    }
                    else{
                        
                        if(farm[i-1][j]=='P'){
                            farm[i-1][j]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                        else if(farm[i+1][j]=='P'){
                            farm[i+1][j]='.';
                            farm[i][j]='.';
                            ans++;
                        }
                        
                    }
                    
                }
                
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}