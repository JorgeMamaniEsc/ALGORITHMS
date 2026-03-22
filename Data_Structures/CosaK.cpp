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

pii no={-1,-1};

struct CosaK{
    int k;
    int s;
    multiset<int> top,rem;
    void ini(int kk){
        k=kk;
        s=0;
    }
    void balance(){
        while(sz(top)<k&&!rem.empty()){
            auto it=prev(rem.end());
            s+=*it;
            top.insert(*it);
            rem.erase(it);
        }
        while(sz(top)>k){
            auto it=top.begin();
            s-=*it;
            rem.insert(*it);
            top.erase(it);
        }
    }
    void add(int x){
        if(x==0) return;
        top.insert(x);
        s+=x;
        balance();
        if(!top.empty()&&!rem.empty()&&(*top.begin())<(*prev(rem.end()))){
            int nrem=*top.begin();
            int ntop=*(prev(rem.end()));
            s+=ntop-nrem;
            top.erase(top.begin());
            rem.erase(prev(rem.end()));
            top.insert(ntop);
            rem.insert(nrem);
        }
    }
    void remove(int x){
        if(x==0) return;
        auto it=top.find(x);
        if(it!=top.end()){
            s-=x;
            top.erase(it);
        }else rem.erase(rem.find(x));
        balance();
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;cin>>tt;
    while(tt--){
        int n,k,ans=0;cin>>n>>k;
        vi a(n);
        vvi ady(n);
        f(i,0,n,1) cin>>a[i];
        f(i,0,n-1,1){
            int x,y;cin>>x>>y;
            x--;
            y--;
            ady[x].pb(y);
            ady[y].pb(x);
        }
        vp in1(n,no),in2(n,no),dp(n,no);
        vi mx(n,-1),h(n,0),pa(n,-1);
        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }
        CosaK tk;
        tk.ini(k-1);
        f(i,0,n,1){
            in1[i]={-1000000000,-i};
            in2[i]={-1000000000,-i};
            dp[i]={-1000000000,-i};
        }

        auto dfs1=[&](auto &self,int u,int p)-> void{
            pa[u]=p;
            bool hoja=true;
            for(int v: ady[u]){
                if(v==p) continue;
                hoja=false;
                self(self,v,u);
                pii cand={in1[v].first+1,in1[v].second};
                if(cand>in1[u]){
                    in2[u]=in1[u];
                    in1[u]=cand;
                    mx[u]=v;
                }else if(cand>in2[u]) in2[u]=cand;
            }
            if(hoja) in1[u]={0,-u};
        };

        auto dfs2=[&](auto &self,int u,int p)-> void{
            for(int v:ady[u]){
                if(v==p) continue;
                pii cand=dp[u];
                if(v!=mx[u]) cand=max(cand,in1[u]);
                else cand=max(cand,in2[u]);

                dp[v]={cand.first+1,cand.second};
                self(self,v,u);
            }
        };

        auto destino=[&](int u,int x)->int{
            if(x==-1) return -1;
            if(x==pa[u]) return -in1[u].second;
            if(x==mx[u]) return -max(in2[u],dp[u]).second;
            return -max(in1[u],dp[u]).second;
        };

        auto raiz=[&](auto &self,int u,int p,int x)->void{
            ans=max(ans,x+tk.s);
            for(int v:ady[u]){
                if(v==p) continue;
                int ov=destino(v,u);
                if(ov!=-1){
                    tk.remove(h[ov]);
                    h[ov]-=a[v];
                    tk.add(h[ov]);
                }

                int nu=destino(u,v);
                if(nu!=-1){
                    tk.remove(h[nu]);
                    h[nu]+=a[u];
                    tk.add(h[nu]);
                }
                self(self,v,u,a[v]);
                if(nu!=-1){
                    tk.remove(h[nu]);
                    h[nu]-=a[u];
                    tk.add(h[nu]);
                }

                if(ov!=-1){
                    tk.remove(h[ov]);
                    h[ov]+=a[v];
                    tk.add(h[ov]);
                }

            }
        };

        dfs1(dfs1,0,-1);
        if(sz(ady[0])==1) dp[0]={0,0};
        else dp[0]={-1000000000,0};
        dfs2(dfs2,0,-1);
        f(i,1,n,1){
            int d=destino(i,pa[i]);
            if(d) h[d]+=a[i];
        }
        f(i,0,n,1) if(sz(ady[i])==1) tk.add(h[i]);
        raiz(raiz,0,-1,a[0]);
        cout<<ans<<endl;
    }
    return 0;
}
