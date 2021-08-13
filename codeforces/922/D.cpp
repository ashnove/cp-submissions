#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;
int const inf = 1e9 + 1;

ll calc_sh(string s){
      int s_cnt = 0;
      ll res = 0;
      for(char ch : s){
            if(ch == 's') s_cnt++;
            else res += s_cnt;
      }
      return res;
}

int main() {

      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      int n; cin >> n;
      vector<string> a(n);
      for(int i = 0; i < n; i++) cin >> a[i];
      sort(a.begin(), a.end(), [&](string &a, string &b){
            return calc_sh(a + b) > calc_sh(b + a);
      });
      
      string ans = "";

      for(int i = 0; i < n; i++) {ans += a[i];}
      cout << calc_sh(ans) << endl;

      return 0;
}