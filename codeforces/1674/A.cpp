#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int x, y; cin >> x >> y;
        if(y % x == 0){ 
            cout << 1 << " " << y/x << endl;
        }
        else cout << "0 0\n";
    }
    return 0;
}