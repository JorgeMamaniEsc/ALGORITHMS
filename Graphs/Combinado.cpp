#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//#define int long long
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
    while(tt--){
        int n,qq;cin>>n>>qq;
        vi a(n),dgr(n,0),dentro(n,-1),dist(n,-1),rama(n,-1),tam(n,0),id(n);
        DSU dsu(n);
        vvi ady(n);
        vvi dp(n+1,vi(32));
        rep(i,0,n,1) {
            cin>>a[i];
            a[i]--;
            dsu.unite(i,a[i]);
            dgr[a[i]]++;
            ady[a[i]].pb(i);
        }
        rep(i,0,n,1) dp[i][0]=a[i];
        rep(j,1,31,1){
            rep(i,0,n,1){
                dp[i][j]=dp[dp[i][j-1]][j-1];
            }
        }
        vb cycle(n,false);
        queue<int> q;
        rep(i,0,n,1) if(dgr[i]==0) q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            int v=a[u];
            dgr[v]--;
            if(dgr[v]==0){
                q.push(v);
            }
        }
        rep(i,0,n,1) {
            if(dgr[i]>0) {
                id[i]=i;
                cycle[i]=true;
                dist[i]=0;
                rama[i]=i;
                q.push(i);
            }
        }
        rep(i,0,n,1){
            if(!cycle[i]) continue;
            if(dentro[i]!=-1) continue;
            dentro[i]=0;
            int u=a[i],cnt=1;
            while(u!=i){
                id[u]=i;
                dentro[u]=cnt++;
                u=a[u];
            }
            tam[i]=cnt;
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:ady[u]){
                if(dist[v]!=-1) continue;
                dist[v]=dist[u]+1;
                rama[v]=rama[u];
                q.push(v);
            }
        }
        rep(jaja,0,qq,1){
            int x,y;cin>>x>>y;
            x--;y--;
            if((dsu.find(x)!=dsu.find(y))||(cycle[x]&&!cycle[y])){
                cout<<-1<<endl;
                continue;
            }
            if(!cycle[x]&&!cycle[y]&&(rama[x]!=rama[y]||dist[y]>dist[x])){
                cout<<-1<<endl;
                continue;
            }
            if(!cycle[x]&&!cycle[y]){
                int d=dist[x]-dist[y];
                int u=x;
                rep(j,0,31,1){
                    if((1<<j)&d){
                        u=dp[u][j];
                    }
                }
                cout<<(u==y?d:-1)<<endl;
                continue;
            }
            if(cycle[x]&&cycle[y]){
                int s=tam[id[x]];
                cout<<(dentro[y]-dentro[x]+s)%s<<endl;
                continue;
            }
            int ans=dist[x];
            x=rama[x];
            int j=abs(dentro[x]-dentro[y]);
            int s=tam[id[x]];
            cout<<ans+(dentro[y]-dentro[x]+s)%s<<endl;
        }
    }
    return 0;
}
