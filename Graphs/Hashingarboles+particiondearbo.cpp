#include<bits/stdc++.h>
using namespace std;

// const int mod = 1e9 + 7;
// using i64 = long long;

// struct mint {};

// int main() {
//   const int maxn = 2e6 + 5;
//   vector<mint> fac(maxn, 1
//   int N, G, E, I;

#define int long long
#define vi vector<long long>
#define rep(a,b,c,d) for(int a=b;a<c;a+=d)
// #define rep(a,d,c) for(int a=d;a<c;a++)
#define endl '\n'
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(x) push_back(x)
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
// using i64 = long long;
const int inf=3000000000000000000;

vi damediv(int n){
  vi ans;
  for(int i=1;i*i<=n;i++){
    if(n%i) continue;
    int k=n/i;
    ans.pb(i);
    if(k!=i) ans.pb(k);
  }
  return ans;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const uint64_t SEED = rng();
uint64_t shift(uint64_t x) {
    x^=SEED;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=SEED;
    return x;
}

void solve() {
  int n;cin>>n;
  vvvi bosque(n);
  rep(i,0,n,1){
    int m;cin>>m;
    vvi temp(m);
    rep(j,0,m-1,1){
      int a,b;cin>>a>>b;
      a--;b--;
      temp[a].pb(b);
      temp[b].pb(a);
    }
    bosque[i]=temp;
  }
  vb uwu;
  vvi ady;
  vi tam,pa,ord,owo;
  map<uint64_t,int> fre;
  auto dfs=[&](auto &&self,int u,int p)->void {
    tam[u]=1;
    pa[u]=p;
    for(int v:ady[u]){
      if(v==p) continue;
      self(self,v,u);
      tam[u]+=tam[v];
    }
  };
  auto hash=[&](auto &&self,int u,int p)->uint64_t {
    int h=1;
    for(int v:ady[u]) if(v!=p&&uwu[v]) h+=shift(self(self,v,u));
    return h;
  };

  auto dfs1=[&](auto &&self,int u,int p,int t)->void {
    owo[u]=1;
    bool ok=true;
    for(int v:ady[u]){
      if(v==p||!uwu[v]) continue;
      self(self,v,u,t);
      owo[u]+=owo[v];
      if(owo[v]>t/2) ok=false;

    }
    if(t-owo[u]>t/2) ok=false;
    if(ok) ord.pb(u);

  };
  auto f=[&](vi &comp)->int {
    for(int u:comp) uwu[u]=true;
    ord.clear();
    dfs1(dfs1,comp[0],-1,sz(comp));
    uint64_t h=-1ULL;
    for(int u:ord) h=min(h,hash(hash,u,-1));
    for(int u:comp) uwu[u]=false;
    return h;
  };
  rep(i,0,n,1){
    ady=bosque[i];
    ord.clear();
    int m=sz(ady);
    owo.assign(m,0);
    uwu.assign(m,false);
    vi aa;
    rep(j,0,sz(ady),1) aa.pb(j);
    int h=f(aa);
    fre[h]++;
  }
  vi ans(n,0);
  rep(i,0,n,1){
    ady=bosque[i];
    int m=sz(ady);
    tam.assign(m,0);
    pa.assign(m,0);

    vi div=damediv(m);
    dfs(dfs,0,0);
    for(int x:div){
      ord.clear();
      int cnt=0;
      owo.assign(m,0);
      uwu.assign(m,false);
      rep(i,0,m,1) if(tam[i]%x==0) cnt++;
      if(cnt!=m/x) continue;
      vb vis(m,false);
      bool ok=false,hay=true;
      int h;
      rep(j,0,m,1){
        if(vis[j]) continue;
        vi comp;
        queue<int> q;
        q.push(j);
        vis[j]=true;
        while(!q.empty()){
          int u=q.front();
          q.pop();
          comp.pb(u);
          for(int v:ady[u]){
            if(vis[v]) continue;
            int k=(pa[v]==u?v:u);
            if(tam[k]%x==0) continue;
            vis[v]=true;
            q.push(v);
          }
        }
        int o=f(comp);
        if(!ok){
          ok=true;
          h=o;
        }else if(h!=o){
          hay=false;
          break;
        }
      }
      if(!hay) continue;
      ans[i]+=(fre[h]-(x==m?1:0));
    }
  }
  rep(i,0,n,1) cout<<ans[i]<<" ";
  cout<<endl;
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
C:
D:
E:
G: graphs graphs and more graphs, isomorfismo,hashing
L:probabilidades mate
*/
