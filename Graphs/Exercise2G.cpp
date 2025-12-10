#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define f(i,a,b,c) for(int i=a;i<b;i+=c)
#define rf(i,a,b,c) for(int i=a;i>=b;i-=c)
#define vi vector<int>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define vp vector<pair<int,int>>
#define vvvp vector<vector<vp>>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define endl '\n'
#define i128 __int128
#define pii pair<int,int>
#define pi 3.14159265358979323846
#define sq2 (sqrt(2.0))
#define inf 1e18

//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//template <typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;



/*
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

struct chash{
    const uint64_t C=(2e18*acos((long double)-1)) + 71;
    const int RANDOM=rng();
    int operator()(int x) const{
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

template <class K,class V> using ht =gp_hash_table<K,V,chash>;
*/


struct TS{
    int n;
    vvi g,gr;
    vi comp,ord,val;
    TS(int n0): n(n0),g(2*n0),gr(2*n0),comp(2*n0),val(n0){}

    void add_or(int x,bool xv,int y,bool yv){
        int a=2*x^(!xv);
        int b=2*y^(!yv);
        g[a^1].pb(b);
        g[b^1].pb(a);
        gr[b].pb(a^1);
        gr[a].pb(b^1);
    }

    bool sat(){
        int N=2*n;
        vc used(N,0);

        function<void(int)> dfs1=[&](int v){
            used[v]=1;
            for(int u: g[v]) if(!used[u]) dfs1(u);
            ord.pb(v);
        };

        function<void(int,int)> dfs2=[&](int v,int c){
            comp[v]=c;
            for(int u:gr[v]) if(comp[u]==-1) dfs2(u,c);
        };

        f(i,0,N,1) if(!used[i]) dfs1(i);

        fill(all(comp),-1);
        int cid=0;
        rf(i,sz(ord)-1,0,1){
            int v=ord[i];
            if(comp[v]==-1) dfs2(v,cid++);
        }
        f(i,0,n,1){
            if(comp[2*i]==comp[2*i^1]) return false;
            val[i]=comp[2*i]>comp[2*i^1];
        }
        return true;
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;

        vvi g(3,vi(n));
        f(i,0,3,1)  f(j,0,n,1) cin>>g[i][j];
        TS s(n);
        f(j,0,n,1){
            int x=g[0][j];
            int y=g[1][j];
            int z=g[2][j];
            auto add=[&](int a,int b){
                bool av=a>0;
                bool bv=b>0;
                s.add_or(abs(a)-1,av,abs(b)-1,bv);
            };
            add(x,y);
            add(y,z);
            add(z,x);
        }
        cout<<(s.sat()?"YES":"NO")<<endl;
    }
    return 0;
}
