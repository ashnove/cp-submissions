#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        string s; cin >> s;
        int a = s[0] - 'a';
        int idx = 26 * a;
        int b = s[1] - 'a';
        cout << idx + b - a + (b<=a) << endl;
    } 
    return 0;
}