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
    return (a*b)/__gcd(a,b);
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

int mex(vi &v,int n){
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

const int mx=1000005;
int criba[mx];

void ini(){
    rep(i,0,mx,1) criba[i]=i;
    rep(i,2,mx,1){
        if(criba[i]!=i) continue;
        rep(j,i*i,mx,i) criba[j]=i;
    }
}

int dameD(int n){
    if(n==1) return 1;
    int t=1;
    vi ans;
    while(n>1){
        int k=criba[n],cnt=0;
        while(n%k==0){
            cnt++;
            n/=k;
        }
        ans.pb(cnt);
    }
    for(int x:ans) t*=(x+1);
    return t;
}

struct BIT{
    int n;
    vi tree;

    void ini(int nn){
        n=nn;
        tree.assign(n+1,0);
    }

    void add(int i,int val){
        for(;i<=n;i+=i&-i) tree[i]+=val;
    }

    int qry(int i){
        int s=0;
        for(;i>0;i-=i&-i) s+=tree[i];
        return s;
    }
    int qry(int l,int r){
        if(l>r) return 0;
        return qry(r)-qry(l-1);
    }
};

struct DSU{
    vi parent;

    DSU(int n){
        parent.resize(n);
        iota(all(parent),0);
    }

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a, int b){
        a=find(a);
        b=find(b);
        if(a!=b) parent[a]=b;
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    ini();
    while(tt--){
        int n,q;cin>>n>>q;
        vi v(n),next(n);
        BIT bit;
        bit.ini(n);
        DSU dsu(n+2);
        rep(i,0,n,1) {
            cin>>v[i];
            next[i]=i+1;
            bit.add(i+1,v[i]);
            if(v[i]<=2) dsu.unite(i,i+1);
        }
        rep(qq,0,q,1){
            int op,l,r;cin>>op>>l>>r;
            if(op==2){
                cout<<bit.qry(l,r)<<endl;
                continue;
            }
            l--;
            r--;
            l=dsu.find(l);
            while(l<=r){
                int x=dameD(v[l]);
                bit.add(l+1,-v[l]);
                bit.add(l+1,x);
                if(x<=2){
                    dsu.unite(l,l+1);
                }
                v[l]=x;
                l=dsu.find(l+1);
            }
        }
    }
    return 0;
}
