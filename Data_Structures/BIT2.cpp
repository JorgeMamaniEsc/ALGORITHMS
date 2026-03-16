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

int mex(vi &v){
    int n=sz(v);
    vi fre(n+2,0);
    f(i,0,n,1) fre[v[i]]++;
    f(i,0,n+2,1) if(!fre[i]) return i;
}
struct BIT{
    int n;
    vi tree;

    BIT(int nn){
        n=nn;
        tree.assign(n+1,0);
    }

    void upd(int i,int x){
        for(;i<=n;i+=(i&-i)){
            tree[i]+=x;
        }
    }
    int qry(int i){
        int t=0;
        for(;i>0;i-=(i&-i)){
            t+=tree[i];
        }
        return t;
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n;cin>>n;
        string s;cin>>s;
        string ps=s;
        reverse(all(ps));
        vector<queue<int>> pos(26);
        f(i,0,n,1) pos[s[i]-'a'].push(i+1);
        int ans=0;
        vi p(n);
        f(i,0,n,1){
            p[i]=pos[ps[i]-'a'].front();
            pos[ps[i]-'a'].pop();
        }
        BIT bit(n);
        f(i,0,n,1){
            ans+=bit.qry(n)-bit.qry(p[i]);
            bit.upd(p[i],1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
