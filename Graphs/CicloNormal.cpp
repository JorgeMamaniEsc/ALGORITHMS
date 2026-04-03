#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define f(i,a,b,c) for(int i=a;i<b;i+=c)
#define rf(i,a,b,c) for(int i=a;i>=b;i-=c)
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
const int MOD=1000000007;
const int inf=5000000000000000000;
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

int dfs(int u,vi &p,vi &color,vvi &ady){
    color[u]=1;
    for(int v:ady[u]){
        if(color[v]==2) continue;
        if(color[v]==1){
            p[v]=u;
            return v;
        }
        p[v]=u;
        int x=dfs(v,p,color,ady);
        if(x!=-1) return x;
    }
    color[u]=2;
    return -1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vvi ady(n);
        f(i,0,m,1){
            int a,b;cin>>a>>b;
            a--;b--;
            ady[a].pb(b);
        }
        vi c(n,0),p(n,-1);
        int u=-1;
        f(i,0,n,1){
            if(c[i]!=0) continue;
            int x=dfs(i,p,c,ady);
            if(x==-1) continue;
            u=x;
            break;
        }
        if(u==-1){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        int x=u;
        vi ans;
        while(true){
            ans.pb(u);
            u=p[u];
            if(u==x) break;
        }
        ans.pb(u);
        reverse(all(ans));
        cout<<sz(ans)<<endl;
        for(int v:ans) cout<<v+1<<" ";
        cout<<endl;
    }
    return 0;
}
