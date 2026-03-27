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

struct Node{
    int mxb,mxc,mnc,mnb,ans1,ans2;
};

struct SegTree{
    int n;
    vector<Node> tree;
    vi a;
    SegTree(int nn){
        n=nn;
        tree.resize(4*n+1);
        a.resize(n+1);
    }

    Node merge(Node izq,Node der){
        Node res;
        res.mxb=max(izq.mxb,der.mxb);
        res.mxc=max(izq.mxc,der.mxc);
        res.mnb=min(izq.mnb,der.mnb);
        res.mnc=min(izq.mnc,der.mnc);
        res.ans1=max({izq.ans1,der.ans1,izq.mxb-der.mnb});
        res.ans2=max({izq.ans2,der.ans2,der.mxc-izq.mnc});

        return res;
    }

    void build(int u,int l,int r){
        if(l==r){
            int x=a[l];
            tree[u].mxb=x+l;
            tree[u].mxc=x-l;
            tree[u].mnb=x+l;
            tree[u].mnc=x-l;
            tree[u].ans1=0;
            tree[u].ans2=0;
            return;
        }
        int mid=(l+r)/2;
        build(2*u,l,mid);
        build(2*u+1,mid+1,r);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }

    void update(int u,int l,int r,int idx,int x){
        if(l==r){
            tree[u].mxb=x+idx;
            tree[u].mxc=x-idx;
            tree[u].mnb=x+idx;
            tree[u].mnc=x-idx;
            tree[u].ans1=0;
            tree[u].ans2=0;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid) update(2*u,l,mid,idx,x);
        else update(2*u+1,mid+1,r,idx,x);
        tree[u]=merge(tree[2*u],tree[2*u+1]);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;cin>>tt;
    while(tt--){
        int n,q;cin>>n>>q;
        SegTree st(n);
        f(i,1,n+1,1) cin>>st.a[i];
        st.build(1,1,n);
        cout<<max(st.tree[1].ans1,st.tree[1].ans2)<<endl;
        f(i,0,q,1){
            int idx,x;cin>>idx>>x;
            st.update(1,1,n,idx,x);
            cout<<max(st.tree[1].ans1,st.tree[1].ans2)<<endl;
        }
    }
    return 0;
}
