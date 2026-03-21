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

struct DSU{
    vi parent,tam;

    DSU(int n){
        parent.resize(n);
        tam.assign(n,1);
        iota(all(parent),0);
    }

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a, int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            parent[a]=b;
        }
    }

    int size(int x){
        return tam[find(x)];
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;cin>>tt;
    while(tt--){
        int m,q;cin>>m>>q;
        string ss;cin>>ss;
        f(qq,0,q,1){
            int ll,rr;cin>>ll>>rr;
            string s=ss.substr(ll-1,rr-ll+1);
            int n=sz(s),l=0,r=0,ans=0;
            vi zzz(n,0),dp(n,-1),ndp(n,0);
            f(i,1,n,1){
                if(i<=r) zzz[i]=min(r-i+1,zzz[i-l]);
                while(i+zzz[i]<n&&s[zzz[i]]==s[i+zzz[i]]) zzz[i]++;
                if(i+zzz[i]-1>r){
                    l=i;
                    r=i+zzz[i]-1;
                }
            }
            zzz[0]=n;
            DSU dsu(n+1);
            rf(i,n-1,0,1){
                r=i+zzz[i]-1;
                int j=dsu.find(i);
                while(j<=r){
                    dp[j]=i;
                    dsu.unite(j,j+1);
                    j=dsu.find(j);
                }
            }
            f(i,0,n,1){
                int l=dp[i];
                if(l==0) ndp[i]=1;
                else if(l!=-1) ndp[i]=ndp[l-1]+1;
                ans+=ndp[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
