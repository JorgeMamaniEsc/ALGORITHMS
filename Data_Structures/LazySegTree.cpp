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

struct SegTree{
    int n;
    vi tree,lazy;
    SegTree(int nn){
        n=nn;
        tree.resize(4*n+1);
        lazy.assign(4*n+1,0);
    }

    void push(int u,int l,int r){
        if(lazy[u]!=0&&l!=r){
            lazy[2*u]+=lazy[u];
            tree[2*u]+=lazy[u];
            lazy[2*u+1]+=lazy[u];
            tree[2*u+1]+=lazy[u];
        }
        lazy[u]=0;
    }

    int merge(int izq,int der){
        return min(izq,der);
    }

    void build(int u,int l,int r){
        if(l==r){
            tree[u]=0;
            return;
        }
        int mid=(l+r)/2;
        build(2*u,l,mid);
        build(2*u+1,mid+1,r);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }

    void update(int u,int l,int r,int ql,int qr,int x){
        if(l>qr||r<ql) return;
        if(ql<=l&&r<=qr){
            tree[u]+=x;
            lazy[u]+=x;
            return;
        }
        push(u,l,r);
        int mid=(l+r)/2;
        update(2*u,l,mid,ql,qr,x);
        update(2*u+1,mid+1,r,ql,qr,x);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }
    int qry(int u,int l,int r,int ql,int qr){
        if(l>qr||r<ql) return inf;
        if(ql<=l&&r<=qr) return tree[u];
        push(u,l,r);
        int mid=(l+r)/2;
        return min(qry(2*u,l,mid,ql,qr),qry(2*u+1,mid+1,r,ql,qr));
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
        vi ans;
        int me=0;
        SegTree st(n);
        st.build(1,0,n);
        multiset<int> libres;
        set<int> fijos;
        for(int x:v){
            if(x<me&&!fijos.count(x)){
                fijos.insert(x);
                st.update(1,0,n,0,x,1);
            }else{
                libres.insert(x);
                int tmr=(x==0?-1:(x-1)/2);

                if(tmr>-1)st.update(1,0,n,0,tmr,1);
            }
            int op=0;
            while(true){
                op=0;
                if(libres.find(me)!=libres.end()){
                    libres.erase(libres.find(me));
                    fijos.insert(me);
                    int xd=(me==0?-1:(me-1)/2);
                    if(xd>-1)st.update(1,0,n,0,xd,-1);
                }else{
                    op=1;
                    st.update(1,0,n,0,me,-1);
                }
                int k=st.qry(1,0,n,0,me);
                if(k>=0) me++;
                else{
                    if(op==0){
                        libres.insert(me);
                        fijos.erase(fijos.find(me));
                        int xd=(me==0?-1:(me-1)/2);
                        if(xd>-1)st.update(1,0,n,0,xd,1);
                    }else st.update(1,0,n,0,me,1);
                    break;
                }
            }
            cout<<me<<" ";
        }
        cout<<endl;
    }
    return 0;
}
