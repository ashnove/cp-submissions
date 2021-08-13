#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;
int const inf = 1e9 + 1;

int main() {

      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      int n; cin >> n;
      vector<string> a(n);
      for(int i = 0; i < n; i++) cin >> a[i];
      sort(a.begin(), a.end(), [](string &a, string &b){
            return a + b < b + a;
      });
      
      string ans = "";
      for(int i = 0; i < n; i++) ans += a[i];
      cout << ans << endl;

      return 0;
}