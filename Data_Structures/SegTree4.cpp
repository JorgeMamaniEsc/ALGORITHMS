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
const int inf=1000000000000000000;
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

//const pii no={-1,-1};
const pii no={-inf,-inf};

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

struct SegTree{
    int n;
    vi tree;
    SegTree(int nn){
        n=nn;
        tree.resize(4*n+1);
    }
    int merge(int izq,int der){
        return max(izq,der);
    }
    void build(int u,int l,int r,vi &v){
        if(l==r){
            tree[u]=v[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*u,l,mid,v);
        build(2*u+1,mid+1,r,v);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }
    void update(int u,int l,int r,int idx,int x){
        if(l==r){
            tree[u]+=x;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid) update(2*u,l,mid,idx,x);
        else update(2*u+1,mid+1,r,idx,x);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }
    int qry(int u,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return tree[u];
        if(r<ql||l>qr) return -inf;
        int mid=(l+r)/2;
        return merge(qry(2*u,l,mid,ql,qr),qry(2*u+1,mid+1,r,ql,qr));
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vi v(n+10,-inf);
        rep(i,0,n,1) cin>>v[i];
        SegTree st(n);
        st.build(1,0,n,v);
        rep(i,0,m,1){
            int x;cin>>x;
            int l=-1,r=n;
            while(r-l>1){
                int mid=(r+l)/2;
                if(st.qry(1,0,n,0,mid)>=x) r=mid;
                else l=mid;
            }
            if(r!=n) st.update(1,0,n,r,-x);
            cout<<(r==n?0:r+1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
