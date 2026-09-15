#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<long long>
#define rep(a,b,c,d) for(int a=b;a<c;a+=d)
#define endl '\n'
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define pb(x) push_back(x)
const int MOD=998244353;
int mp(int b,int e){
  int ans=1;
  while(e>0){
    if(e&1) ans=(ans*b)%MOD;
    e>>=1;
    b=(b*b)%MOD;
  }
  return ans;
}

using cd = complex<long double>;
const long double PI = acos(-1.0L);

void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        long double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) for (cd &x : a) x /= n;
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

pair<vi,int> f(vi &a,vi &b){
  int n=sz(a);
  vi a1,a2,b1,b2;
  rep(i,0,n,1){
    if(a[i]<0) a2.pb(a[i]);
    else a1.pb(a[i]);
    if(b[i]<0) b2.pb(b[i]);
    else b1.pb(b[i]);
  }
  sort(rall(a1));
  sort(rall(b1));
  sort(all(a2));
  sort(all(b2));
  vi ans,na,nb;
  int m=min(sz(a1),sz(b1));
  rep(i,0,m,1) ans.pb(a1[i]*b1[i]);
  rep(i,m,sz(a1),1) na.pb(a1[i]);
  rep(i,m,sz(b1),1) nb.pb(b1[i]);
  m=min(sz(a2),sz(b2));
  rep(i,0,m,1) ans.pb(a2[i]*b2[i]);
  rep(i,m,sz(a2),1) na.pb(a2[i]);
  rep(i,m,sz(b2),1) nb.pb(b2[i]);

  sort(all(na),[&](int i,int j){
    return abs(i)<abs(j);
  });
  sort(all(nb),[&](int i,int j){
    return abs(i)<abs(j);
  });
  m=sz(na);
  //reverse(all(nb));
  int u=sz(ans);
  vi owo=multiply(na,nb);
  sort(rall(ans));
  rep(i,0,m,1){
    ans.pb(owo[i]);
  }
  return {ans,u};
} 

void solve() {
  int n;cin>>n;
  vi a(n),b(n);
  rep(i,0,n,1) cin>>a[i];
  rep(i,0,n,1) cin>>b[i];
  auto [mx,k1]=f(a,b);
  rep(i,0,n,1) b[i]=-b[i];
  auto [mn,k2]=f(a,b);
  int t1=0,t2=0;
  rep(i,0,n,1){
    t1+=mx[i];
    t2-=mn[i];
   
    cout<<t2<<" "<<t1<<endl;
    if(i>=k1){
      t1-=mx[i];
    }
    if(i>=k2){
      t2+=mn[i];
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  //cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

/* pa comentar de los probs : nivel, tag, tu prima
escribe pe cual tas haciendo
A:
B: sortings + two pointers + greedy greedy an more greedyyyy
C:
D:
E:
G:
H: dp
L:
M: toy aca dp
*/
