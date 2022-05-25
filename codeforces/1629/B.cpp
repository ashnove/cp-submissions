#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int l,r,k;
        cin >> l >> r >> k;
        if(l == r){
            if(l == 1) cout << "NO\n";
            else cout << "YES\n";
            continue;
        }
        cout << ( (r - l + 2 - (l%2==0)) / 2 <= k ? "YES\n" : "NO\n" );
    } 
    return 0;
}