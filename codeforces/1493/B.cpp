/*@author : ashnove*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl;
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define what_is(x) cerr << #x << " is " << x << endl;
#define mat vector<vector<ll>>
mat cn(ll n, ll m) {return vector< vector<ll> >(n, vector<ll>(m));}
bool comp1(char &s1, char &s2) {return s1 > s2;}
bool comp2(const pair<ll, pair<ll, ll>> &a,  const pair<ll, pair<ll, ll>> &b) {
      if (a.first > b.first ) return 1;
      if ( a.first == b.first && a.S.S > b.S.S ) return 1;
      return 0;
}

ll const mod = 1e9 + 7;
ll const inf = 1e17;
ll const maxn = 2e5 + 1;
ll digLen(ll x){
      ll res = 0;
      while(x) x/=10, res++;
      return res;
}
pair<ll,ll> next_time(ll h1, ll m1, ll h, ll m){

      m1++;
      if(m1>=m)m1=0,h1++;
      if(h1>=h)h1=0;

      return {h1, m1};
}
bool isValid(ll h1, ll m1, ll h, ll m){
      return ( h1>=0&&h1<h && m1>=0&&m1<m );
}

void solve()
{
      ll h,m; cin >> h >> m;
      string s; cin >> s;
      set<ll> mirr; 
      mirr.insert(0);
      mirr.insert(1);
      mirr.insert(8);
      mirr.insert(5);
      mirr.insert(2);
      ll const mirr2[10] = {0 , 1, 5, -1, -1, 2, -1, -1, 8, -1};
      string htring=s.substr(0,2), mstring=s.substr(3,2);
      ll hval = stoll(htring), mval=stoll(mstring);
      pair<ll,ll> cur = {hval, mval};
      
       
      while(1){
            // hval = cur.F;
            // mval = cur.S;
            ll c1 = hval, c2 = mval;
            ll revh=0, revm = 0;
            bool ok = 1;
            // cout << hval << " " << mval << endl;
            while(c1>0){
                  revh = revh*10 + mirr2[c1%10];
                  if(mirr.count(c1%10)==0)ok=0;
                  c1/=10;
            }
            while(c2>0){
                  revm = revm*10 + mirr2[c2%10];
                  if(mirr.count(c2%10)==0)ok=0;
                  c2/=10;
            }
            // cout << ok << endl;
            if(ok==0){
                    cur = next_time(hval, mval, h, m);
                    hval = cur.F;
                    mval = cur.S;
                    continue;
            }
            
            string hh = to_string(hval);
            string mm = to_string(mval);
            reverse(hh.begin(), hh.end());
            reverse(mm.begin(), mm.end());
            while(hh.size() < 2)
                hh+='0';
            while(mm.size() < 2)
                mm+='0';
              if(hval < 10) revh*=10;
              if(mval < 10) revm*=10;

            if(isValid(revm, revh, h, m)){

                  reverse(hh.begin(), hh.end());
                  reverse(mm.begin(), mm.end());
                  cout << hh << ":" << mm << endl;
                  return;

            }
            
            cur = next_time(hval, mval, h, m);
            hval = cur.F;
            mval = cur.S;
      }

}


int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
//*
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
      /**/
      ll t;
      /*/t = 1;
      /*/cin >> t; /**/
      f(testcases, 0, t) {
            //cout << "Case #" <<testcases+1<<": ";
            solve();
      }
      // printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
}