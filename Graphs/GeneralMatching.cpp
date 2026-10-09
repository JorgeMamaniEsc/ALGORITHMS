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
//plantillas del kactl 
int matInv(vvi& A) {
    int n = sz(A); vi col(n);
    vvi tmp(n, vi(n));
    rep(i,0,n,1) tmp[i][i] = 1, col[i] = i;
    rep(i,0,n,1) {
        int r = i, c = i;
        bool ok=false;
        rep(j,i,n,1){
            rep(k,i,n,1){
                if(A[j][k]!=0){
                    r=j;
                    c=k;
                    ok=true;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) return i;

        A[i].swap(A[r]); tmp[i].swap(tmp[r]);
        rep(j,0,n,1)swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
        swap(col[i], col[c]);
        int v = A[i][i];
        int iv=mp(v,MOD-2);
        rep(j,i+1,n,1) {
            int f = A[j][i]*iv%MOD;
            A[j][i] = 0;
            rep(k,i+1,n,1) A[j][k] = (A[j][k]-f*A[i][k]%MOD+MOD)%MOD;
            rep(k,0,n,1) tmp[j][k] = (tmp[j][k]-f*tmp[i][k]%MOD+MOD)%MOD;
        }
        rep(j,i+1,n,1) A[i][j] = A[i][j]*iv%MOD;
        rep(j,0,n,1) tmp[i][j] =tmp[i][j]*iv%MOD;
        A[i][i] = 1;
    }
    for (int i = n-1; i > 0; --i) rep(j,0,i,1) {
        int v = A[j][i];
        rep(k,0,n,1) tmp[j][k] = (tmp[j][k]-v*tmp[i][k]%MOD+MOD)%MOD;
    }
    rep(i,0,n,1) rep(j,0,n,1) A[col[i]][col[j]] = tmp[i][j];
    return n;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<pii> generalMatching(int N, vector<pii>& ed) {
    vector<vector<int>> mat(N, vector<int>(N)), A;
    for (pii pa : ed) {
        int a = pa.first, b = pa.second, r = rng() % MOD;
        mat[a][b] = r, mat[b][a] = (MOD - r) % MOD;
    }
    int r = matInv(A = mat);
    int M = 2*N - r, fi, fj;
    assert(r % 2 == 0);
    if (M != N) do {
        mat.resize(M, vector<int>(M));
        rep(i,0,N,1) {
            mat[i].resize(M);
            rep(j,N,M,1) {
                int rn = rng() % MOD;
                mat[i][j] = rn, mat[j][i] = (MOD - rn) % MOD;
            }
        }
    } while (matInv(A = mat) != M);
    vi has(M, 1); vector<pii> ret;
    rep(it,0,M/2,1) {
        rep(i,0,M,1) if (has[i])
        rep(j,i+1,M,1) if (A[i][j] && mat[i][j]) {
        fi = i; fj = j; goto done;
        } assert(0); done:
        if (fj < N) ret.emplace_back(fi, fj);
        has[fi] = has[fj] = 0;
        rep(sw,0,2,1) {
            int a = mp(A[fi][fj], MOD-2);
            rep(i,0,M,1) if (has[i] && A[i][fj]) {
                int b = A[i][fj] * a % MOD;  
                rep(j,0,M,1) A[i][j] = (A[i][j] - A[fi][j] * b%MOD+MOD) % MOD;
            }
            swap(fi,fj);
        }
    }
    return ret;
}


void xdxd(){
    int n,m;cin>>n>>m;
    vvi ady(n);
    rep(i,0,m,1){
        int a,b;cin>>a>>b;
        ady[a].pb(b);
    }
    vvc ok(n,vc(n,false));
    auto dfs=[&](auto &&self,int u,int i)->void{
        ok[i][u]=true;
        for(int v:ady[u]) if(!ok[i][v])self(self,v,i);
    };
    rep(i,0,n,1) dfs(dfs,i,i);
    vp aris;
    rep(i,0,n,1) rep(j,i+1,n,1) if(!ok[i][j]&&!ok[j][i]) aris.pb({i,j});
    cout<<n-sz(generalMatching(n,aris))<<endl;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
	cout<<fixed;
    int tt=1;
    //cin>>tt;
    while(tt--){
        xdxd();
    }
    return 0;
}
