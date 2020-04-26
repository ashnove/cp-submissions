
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define mod 1000000001
#define Fi(n) for(ll i=0;i<n;i++)
#define Fj(n) for(ll j=0;j<n;j++)
#define Fiab(a,b) for(ll i=a;i<b;i++)
#define Fjab(a,b) for(ll j=a;j<b;j++)
#define sexy ios_base::sync_with_stdio(false);cin.tie(NULL);
#define txti freopen("input.txt", "r", stdin);
#define txto freopen("output.txt", "w", stdout);

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
        
    ll tt;
    cin>>tt;
    while(tt-->0){
        
        
        string t;
        cin>>t;
        ll n = t.length();
        vector<char> woo;
        bool marked[2];
        marked[0]=false;
        marked[1]=false;
        Fi(n){
            if(!marked[int(t[i])-48]){
                woo.push_back(t[i]);
                marked[int(t[i])-48]=true;
            }
        }
        ll m = (2*n)/woo.size();    
        
        for(ll i=0; i<m;i++){
            for (ll j=0;j<woo.size();j++) 
                cout << woo[j];
             
        }
       cout<<endl;
        
    }
    
    return 0;
}