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
const int MOD=998244353;
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

int timee=0;
vi tin,tout;
vvi up,ady;

void dfs(int u,int p){
    tin[u]=++timee;
    up[u][0]=p;
    f(i,1,20,1) up[u][i]=up[up[u][i-1]][i-1];
    for(int v:ady[u]){
        if(v!=p) dfs(v,u);
    }
    tout[u]=++timee;
}

bool is(int u,int v){
    if(u==0) return true;
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int lca(int u,int v){
    if(is(u,v)) return u;
    if(is(v,u)) return v;
    rf(i,19,0,1) if(!is(up[u][i],v)) u=up[u][i];
    return up[u][0];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vvi peso(n+1);
        f(i,1,n+1,1){
            int x;cin>>x;
            peso[x].pb(i);
        }
        timee=0;
        int lp=0;
        ady.assign(n+1,{});
        tin.assign(n+1,0);
        tout.assign(n+1,0);
        up.assign(n+1,vi(30));
        f(i,0,n-1,1){
            int a,b;cin>>a>>b;
            ady[a].pb(b);
            ady[b].pb(a);
        }
        dfs(1,0);
        int ans=0;
        rf(i,n,0,1){
            if(peso[i].empty()) continue;
            if(lp!=0){
                for(int u:peso[i]){
                    if(!is(u,lp)){
                        ans=u;
                        break;
                    }
                }
            }
            if(ans!=0) break;
            for(int u:peso[i]){
                if(lp==0) lp=u;
                else lp=lca(lp,u);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
