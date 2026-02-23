#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define f(i,a,b,c) for(int i=a;i<b;i+=c)
#define rf(i,a,b,c) for(int i=a;i>=b;i-=c)
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

const int MOD=998244353;
const int inf=10000000000000000;
int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}

int sgn(int n){
    if(n==0) return 0;
    return (n<0?-1:1);
}


struct STMX{
    int n,log;
    vvi st;
    vi lg;

    STMX(vi &v){
        build(v);
    }

    void build(vi &v){
        n=sz(v);
        lg.assign(n+1,0);

        f(i,2,n+1,1) lg[i]=lg[i/2]+1;

        log=lg[n]+1;
        st.assign(log,vi(n));

        f(i,0,n,1) st[0][i]=v[i];

        f(k,1,log,1) f(i,0,n-(1ll<<k)+1,1) st[k][i]=max(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
    }

    int qry(int l,int r){
        int len=r-l+1;
        int k=lg[len];
        return max(st[k][l],st[k][r-(1ll<<k)+1]);
    }
};

struct STMN{
    int n,log;
    vvi st;
    vi lg;

    STMN(vi &v){
        build(v);
    }

    void build(vi &v){
        n=sz(v);
        lg.assign(n+1,0);

        f(i,2,n+1,1) lg[i]=lg[i/2]+1;

        log=lg[n]+1;
        st.assign(log,vi(n));

        f(i,0,n,1) st[0][i]=v[i];

        f(k,1,log,1) f(i,0,n-(1ll<<k)+1,1) st[k][i]=min(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
    }

    int qry(int l,int r){
        int len=r-l+1;
        int k=lg[len];
        return min(st[k][l],st[k][r-(1ll<<k)+1]);
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        //unu
    }

    return 0;
}
