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
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//template <typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ld eps=1e-9;
//const int MOD=998244353;
const int MOD=1000000007;
const int inf=1000000000000000000;
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

struct SegTree{
    int n;
    vi tree;
    SegTree(int nn){
        n=nn;
        tree.resize(4*n+1);
    }
    int merge(int izq,int der){
        return min(izq,der);
    }
    void build(int u,int l,int r){
        if(l==r){
            tree[u]=inf;
            return;
        }
        int mid=(l+r)/2;
        build(2*u,l,mid);
        build(2*u+1,mid+1,r);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }
    void update(int u,int l,int r,int idx,int x){
        if(l==r){
            tree[u]=x;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid) update(2*u,l,mid,idx,x);
        else update(2*u+1,mid+1,r,idx,x);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }
    int qry(int u,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return tree[u];
        if(r<ql||l>qr) return inf;
        int mid=(l+r)/2;
        return merge(qry(2*u,l,mid,ql,qr),qry(2*u+1,mid+1,r,ql,qr));
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int mx=1000000;
        vi mnp(mx+1,inf),mnc(mx+1,inf),prep(mx+1,inf),prec(mx+1,inf);
        int n;cin>>n;
        vp v(n);
        rep(i,0,n,1) cin>>v[i].first;
        rep(i,0,n,1) cin>>v[i].second;
        rep(i,0,n,1){
            auto [x,y]=v[i];
            mnp[x]=min(mnp[x],y);
            mnc[y]=min(mnc[y],x);
        }
        prep[0]=mnp[0];
        prec[0]=mnc[0];
        rep(i,1,mx+1,1){
            prep[i]=min(prep[i-1],mnp[i]);
            prec[i]=min(prec[i-1],mnc[i]);
        }
        int m;cin>>m;
        vi tp(m),tc(m),d(m),pos1(m),pos2(m);
        rep(i,0,m,1) cin>>tp[i];
        rep(i,0,m,1) cin>>tc[i];
        rep(i,0,m,1) cin>>d[i];
        rep(i,0,m,1) {
            pos1[i]=i;
            pos2[i]=i;
        }
        vi ans(m,inf);

        rep(i,0,m,1){
            int tpj=tp[i],tcj=tc[i];
            if(tpj>0&&tcj>0&&prep[tpj-1]<tcj) ans[i]=0;
            if(tpj>0&&prep[tpj-1]!=inf) ans[i]=min(ans[i],min(tcj+d[i],prep[tpj-1]));
            if(tcj>0&&prec[tcj-1]!=inf) ans[i]=min(ans[i],min(tpj+d[i],prec[tcj-1]));
            ans[i]=min(ans[i],tpj+tcj+2*d[i]);
            //dbg(ans[i]);
        }

        sort(all(pos1),[&](int i,int j){
            return(d[i]+tp[i]>d[j]+tp[j]);
        });
        sort(all(pos2),[&](int i,int j){
            return(d[i]+tc[i]>d[j]+tc[j]);
        });
        SegTree stp(mx),stc(mx);
        stp.build(1,0,mx);
        stc.build(1,0,mx);
        vp qp,qc;
        rep(i,0,mx+1,1){
            int sp=i+mnp[i],sc=i+mnc[i];
            if(mnp[i]!=inf)stp.update(1,0,mx,i,sp);
            if(mnc[i]!=inf)stc.update(1,0,mx,i,sc);
            if(mnp[i]!=inf)qp.pb({sp-i,i});
            if(mnc[i]!=inf)qc.pb({sc-i,i});
        }
        sort(all(qp));
        sort(all(qc));
        for(int i:pos1){
            int x=tp[i]+d[i],y=tc[i]+d[i];
            while(!qp.empty()&&qp.back().first>x) {
                auto [val,idx]=qp.back();
                stp.update(1,0,mx,idx,x);
                qp.pop_back();
            }
            int tpj=tp[i];
            if(x>0) ans[i]=min(ans[i],stp.qry(1,0,mx,0,x-1));
        }
        for(int i:pos2){
            int x=tc[i]+d[i],y=tc[i]+d[i];
            while(!qc.empty()&&qc.back().first>x) {
                auto [val,idx]=qc.back();
                stc.update(1,0,mx,idx,x);
                qc.pop_back();
            }
            if(x>0) ans[i]=min(ans[i],stc.qry(1,0,mx,0,x-1));
        }
        rep(i,0,m,1) cout<<ans[i]<<endl;
    }

    return 0;
}
