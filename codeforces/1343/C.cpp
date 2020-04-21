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
            ll a[n];
            Fi(n)
                    cin>>a[i];
            bool pos = true;
            if(a[0]>=0)
                pos = true;
            else
                pos = false;
            ll start=0,end =0,sum=0,resi = 0;
            for(ll i=0;i<n;i++){
                
                if(pos){
                    
                    if(a[i]<0 || (a[i]>=0 && i==n-1)){
                        if(a[i]>=0 && i==n-1)
                        end=n;
                        else
                        end = i;
                        //cout<<*max_element(a+start,a+end)<<" ";
                        sum += *max_element(a+start,a+end);
                        pos = false;
                        start = i;
                        if(a[i]<0&&i==n-1)
                        resi = a[i];
                        
                    }
                }
                else{
                    
                    if(a[i]>=0 || (a[i]<0 && i==n-1)){
                        if((a[i]<0 && i==n-1))
                        end=n;
                        else
                        end = i;
                        //cout<<*max_element(a+start,a+end)<<" ";
                        
                        sum += *max_element(a+start,a+end);
                        pos = true;
                        start = i;
                        if(a[i]>=0&&i==n-1)
                        resi = a[i];
                    }
                    
                }
                    
                    
            } 
        
            cout<<sum+resi<<endl;
               
            
    }
    
    
    return 0;
}