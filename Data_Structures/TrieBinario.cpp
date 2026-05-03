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
#define vs vector<string>
#define vc vector<char>
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
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//template <typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ld eps=1e-9;
const int MOD=998244353;
const int inf=3000000000000000000;
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

int ask(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    int x;cin>>x;
    return x;
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

int distn(pii p1,pii p2){
    auto [x1,y1]=p1;
    auto [x2,y2]=p2;
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

struct Node{
    int next[2];
    int cnt,ones;
    Node(){
        next[0]=next[1]=-1;
        cnt=0;
        ones=0;
    }
};

struct Trie{
    vector<Node> nodes;
    Trie(){
        nodes.pb(Node());
    }

    void add(int x){
        int u=0;
        nodes[u].cnt++;
        nrep(i,29,0,1){
            int b=(x>>i)&1;
            if(nodes[u].next[b]==-1){
                nodes[u].next[b]=sz(nodes);
                nodes.pb(Node());
                nodes.back().ones=nodes[u].ones+b;
            }
            u=nodes[u].next[b];
            nodes[u].cnt++;

        }
    }
    int qry(int u){
        int cnt1=0,cnt0=0;

        if(nodes[u].next[0]!=-1 ) cnt0=nodes[nodes[u].next[0]].cnt;
        if(nodes[u].next[1]!=-1 ) cnt1=nodes[nodes[u].next[1]].cnt;
        int s=0;
        int ones=nodes[u].ones;
        s=((cnt0*cnt1)%MOD*(2*ones+3))%MOD;
        if(nodes[u].next[0]==-1&&nodes[u].next[1]==-1) s=(s+((nodes[u].cnt*nodes[u].cnt)%MOD)*(ones+1))%MOD;
        return s;
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vi v(n);
        rep(i,0,n,1) cin>>v[i];

        Trie tri;
        int ans=0;
        rep(i,0,n,1){
            tri.add(v[i]);
        }
        vb vis(sz(tri.nodes)+1,false);
        rep(i,0,n,1){
            int u=0;
            if(!vis[u]){
                vis[u]=true;
                ans=(ans+tri.qry(u))%MOD;
            }
            nrep(j,29,0,1){
                int b=0;
                if((1ll<<j)&v[i]) b=1;
                u=tri.nodes[u].next[b];
                if(vis[u]) continue;
                vis[u]=true;
                ans=(ans+tri.qry(u))%MOD;
            }
        }
        int g=(n*n)%MOD;
        cout<<(ans*mp(g,MOD-2))%MOD<<endl;
    }
    return 0;
}
