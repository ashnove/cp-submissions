#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
    int t = 1;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        ll a,b,c; cin >> a >> b >> c;
    	ll x,y; cin >> x >> y;
    	x-=a;
    	y-=b;
    	if(x < 0) x = 0;
    	if(y < 0) y = 0;
    	cout << (x+y <= c ? "YES\n" : "NO\n");
    }

	return 0;
}