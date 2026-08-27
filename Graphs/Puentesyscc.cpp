#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

//using namespace __gnu_pbds;
#define int long long
#define rep(i,a,b,c) for(int i=a;i<b;i+=c)
#define nrep(i,a,b,c) for(int i=a;i>=b;i-=c)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr<<" ====================== "<<endl
#define vi vector<int>
#define vd vector<long double>
#define vvd vector<vd>
#define vvvd vector<vvd>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vb vector<bool>
#define vp vector<pair<int,int>>
#define vvp vector<vp>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define endl '\n'
#define i128 __int128
#define pii pair<int,int>
#define pi 3.14159265358979323846
#define sq2 (sqrt(2.0))
#define ld long double
#define vmp vector<map<int,int>>
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//template <typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ld eps=1e-9;
//const int MOD=998244353;
const int MOD=1000000007;
//const int MOD=1000003;
//const int inf=2000000000000000000;
const int inf=1000000000000000000LL;

int mpv1(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b);
        b=(b*b);
        e>>=1;
    }
    return s;
}
int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char mov[4]={'D','U','R','L'};

const pii no={-1,-1};
//const pii no={-inf,-inf};

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}
int sgn(int x){
    if(x==0) return 0;
    return (x<0?-1:1);
}


bool choque(pii a,pii b){
    if(a>b) swap(a,b);
    auto [l1,r1]=a;
    auto [l2,r2]=b;
    if(r1>=l2) return true;
    return false;
}

int mex(vi &v){
    int n=sz(v);
    vi fre(n+2,0);
    rep(i,0,n,1) if(v[i]>=0&&v[i]<=n+1) fre[v[i]]++;
    rep(i,0,n+2,1) if(fre[i]==0) return i;
}

int damek(int x){
    int t=0;
    while(x%2==0){
        x/=2;
        t++;
    }
    return t;
}
int disth(pii a,pii b){
    auto [a1,a2]=a;
    auto [b1,b2]=b;
    return abs(a1-b1)+abs(a2-b2);
}
bool esprimo(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
vi damediv(int n){
    vi ans;
    for(int i=1;i*i<=n;i++){
        if(n%i) continue;
        ans.pb(i);
        if(i*i!=n) ans.pb(n/i);
    }
    return ans;
}

vi damepri(int n){
    vi ans;
    int nn=n;
    for(int i=2;i*i<=n;i++){
        if(nn%i)continue;
        ans.pb(i);
        while(nn%i==0) nn/=i;
    }
    if(nn>1) ans.pb(nn);
    return ans;
}

bool mismarecta(pii p1,pii p2,pii p3){
    auto [x1,y1]=p1;
    auto [x2,y2]=p2;
    auto [x3,y3]=p3;
    return (((y2-y1)*(x3-x1))==((y3-y1)*(x2-x1)));
}

int disteu(pii p1,pii p2){
    auto [x1,y1]=p1;
    auto [x2,y2]=p2;
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

ld raizeu(pii p1,pii p2){
    auto [x1,y1]=p1;
    auto [x2,y2]=p2;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int pcruz(pii o,pii p1,pii p2){
    auto [x1,y1]=p1;
    auto [x2,y2]=p2;
    auto [o1,o2]=o;
    return (x1-o1)*(y2-o2)-(y1-o2)*(x2-o1);
}

int next2(int n){
    int x=1;
    while(x<n) x<<=1ll;
    return x;
}
int sd(int x){
    int t=0;
    while(x>0){
        t+=x%10;
        x/=10;
    }
    return t;
}
int tam10(int x){
    int t=0;
    if(x==0) return 1;
    while(x>0){
        x/=10;
        t++;
    }
    return t;
}



string sumastring(string a,string b){
    reverse(all(a));
    reverse(all(b));
    int n=max(sz(a),sz(b));
    int c=0;
    string ans;
    rep(i,0,n,1){
        int x=(sz(a)<=i?0:a[i]-'0'),y=(sz(b)<=i?0:b[i]-'0');
        int t=x+y+c;
        char d=(t%10)+'0';
        ans.pb(d);
        c=t/10;
    }
    if(c>0) ans.pb(c+'0');
    reverse(all(ans));
    return ans;
}

pii intersec(pii p1,pii p2){
    if(!choque(p1,p2)) return no;
    auto [x1,y1]=p1;
    auto [x2,y2]=p2;
    int a=max(x1,x2);
    int b=min(y1,y2);
    return {a,b};
}



string apqpqpqpa(int x){
    string ans;
    nrep(j,29,0,1){
        if((1<<j)&x) ans.pb('1');
        else if(sz(ans))ans.pb('0');
    }
    return ans;
}

int raiz1(int x){
    int k=(int)sqrt(x);
    if(k*k==x) return k;
    return -1;
}

pii juntar(pii p1,pii p2){
    if(p2<p1) swap(p1,p2);
    pii p={min(p1.first,p2.first),max(p1.second,p2.second)};
    return p;
}

int piso(int x,int y){
    if(x>=0) return x/y;
    return (x-y+1)/y;
}

int techo(int x,int y){
    if(x>=0) return (x+y-1)/y;
    return x/y;
}


int conv(string x){
    int n=sz(x),t=0;
    rep(i,0,n,1) if(x[i]=='1')t+=(1<<i);
    return t;
}

vi cambase(int x,int b){
    vi v;
    if(x==0) v.pb(0);
    while(x>0){
        int c=x%b;
        v.pb(c);
        x/=b;
    }
    reverse(all(v));
    return v;
}

char xo(char c){
    if(c=='1') return '0';
    return '1';
}

struct cosa{
    int l,r,x;
    bool operator<(const cosa &o) const{
        if(l!=o.l) return l<o.l;
        return r<o.r;
    }
};


void mikunakano(){
    int n,m;cin>>n>>m;
    vvp ady(n);
    vp aris(m);
    rep(i,0,m,1){
        int a,b;cin>>a>>b;
        a--;b--;
        ady[a].pb({b,i});
        ady[b].pb({a,i});
    }
    vi tin(n,-1),low(n);
    int time=0;
    set<int> malas;
    auto dfs=[&](auto &&self,int u,int p)->void{
        tin[u]=time;
        low[u]=time;
        time++;
        for(auto &[v,idx]:ady[u]){
            if(v==p) continue;

            if(tin[v]!=-1){
                low[u]=min(low[u],tin[v]);
                continue;
            }
            self(self,v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>tin[u]) malas.insert(idx);
        }
    };
    dfs(dfs,0,-1);
    vb vis(n,false);
    int raiz,mx=-1,t=0;
    auto dfs1=[&](auto &&self,int u)->void{
        vis[u]=true;
        t++;
        for(auto &[v,idx]:ady[u]) if(!vis[v]&&!malas.count(idx)) self(self,v);
    };
    rep(i,0,n,1){
        if(vis[i]) continue;
        t=0;
        dfs1(dfs1,i);
        if(t>mx){
            mx=t;
            raiz=i;
        }
    }
    fill(all(vis),false);
    auto dfs2=[&](auto &&self,int u,int p)->void{
        vis[u]=true;
        for(auto &[v,idx]:ady[u]){
            if(v==p) continue;
            if(vis[v]){
                aris[idx]={v,u};
                continue;
            }
            if(malas.count(idx)) aris[idx]={v,u};
            else aris[idx]={u,v};
            self(self,v,u);
        }
    };
    dfs2(dfs2,raiz,-1);
    cout<<mx<<endl;
    for(auto [x,y]:aris) cout<<x+1<<" "<<y+1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
	cout<<fixed;
    int tt=1;
    //ini();
    //cin>>tt;
    while(tt--){
        mikunakano();
    }

    return 0;
}
