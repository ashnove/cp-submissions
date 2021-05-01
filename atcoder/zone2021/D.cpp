/*
      @author : ashnove
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define F first
#define S second
#define Th third
// #define endl "\n"
#define nl cout << endl;
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; i++)
#define what_is(x) cerr << #x << " is " << x << endl;
#define ar vector<ll>
#define mat vector<vector<ll>>
mat cn(ll n, ll m) {return vector<vector<ll>>(n, vector<ll>(m));}
bool comp1(char &allVal, char &s2) { return allVal > s2; }
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first)
            return 1;
      if (a.first == b.first && a.S.S > b.S.S)
            return 1;
      return 0;
}
class Pair { public: ll first, second;};
bool comp3(const Pair &a, const Pair &b) {
      if (a.F > b.F) return 1; return 0;
}
class Trips { public: ll first, second, third;};
bool comp4(const Trips &a, const Trips &b) {
      if (a.Th > b.Th) return 1; return 0;
}

ll const mod = 1e9 + 7;
ll const inf = 1e9;
ll const maxn = 5e5 + 1;

void solve()
{
      ll t = 1;
      // cin >> t;
      for (ll tt = 1; tt <= t; tt++) {
            string s; cin >> s;

            ll rev = 0;
            deque<char> ans;
            for(ll i = 0; i < s.size(); i++){

                  if(s[i] == 'R') rev^=1;
                  else{
                        if(rev){
                              ans.push_front(s[i]);
                        }
                        else ans.push_back(s[i]);
                  }

            }
            string res =  "";
            if(!rev){
                  map<char,ll> used;
                  while(!ans.empty()){
                        // if(used[ans.front()]) {ans.pop_front();continue;}
                        used[ans.front()] = 1;
                        res += ans.front();
                        ans.pop_front();
                  }
            }else{
                  map<char,ll> used;
                  while(!ans.empty()){
                        // if(used[ans.back()]) {ans.pop_back();continue;}
                        used[ans.back()] = 1;
                        res += ans.back();
                        ans.pop_back();
                  }
            }

            stack<char> ss;
            
            for(ll i = 0; i < res.size(); i++){

                  if(ss.empty())
                        ss.push(res[i]);
                  else{

                        bool ok = 0;
                        while(!ss.empty() && ss.top() == res[i])
                              ss.pop(), ok = 1;
                        if(!ok) ss.push(res[i]);

                  }

            }   

            string pp = "";
            while(!ss.empty())
            {
                  pp+=ss.top(); ss.pop();
            }

            for(ll i = pp.size()-1; i >= 0; i--)
                  cout <<pp[i];
      }
}



int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      //*
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif/**/
      solve();
      // cout << "Case #" <<tt<<": ";
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}