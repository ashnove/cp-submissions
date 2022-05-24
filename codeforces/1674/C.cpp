#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        string a; cin >> a;
        string b; cin >> b;
        int n = a.size();
        bool cntA = 0;
        for(char e : b) if(e == 'a') cntA = 1;
        if(b == "a") cout << 1 << endl;
        else if(cntA) cout << -1 << endl;
        else cout << (1ll << n) << endl;
    } 
    return 0;
}