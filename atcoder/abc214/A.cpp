#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double;
int const inf = 1e9 + 1;
int const maxn = 1e5 + 1;
vector<ll> adj[maxn];

int main() {

      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      ll n; cin >> n;
      cout << (n >= 212 ? 8 : (n >= 126 ? 6 : 4));

      return 0;
}