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
    f(i,0,n,1) if(v[i]<n+2) fre[v[i]]++;
    f(i,0,n+2,1) if(!fre[i]) return i;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vvp ady(n);
        f(i,0,m,1){
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            ady[a].pb({b,c});
        }
        multiset<tuple<int,int,int>> q;
        q.insert({0,0,0});
        vvi dp(n,vi(2,inf));
        dp[0][0]=0;
        while(!q.empty()){
            auto it=q.begin();
            auto [d,u,x]=*it;
            q.erase(it);
            if((x==1&&d>dp[u][1])||(x==0&&d>dp[u][0])) continue;
            for(auto [v,w]:ady[u]){
                if(x==0){
                    if(d+w<dp[v][0]){
                        dp[v][0]=d+w;
                        q.insert({d+w,v,0});
                    }
                    if(d+w/2<dp[v][1]){
                        dp[v][1]=d+w/2;
                        q.insert({d+w/2,v,1});
                    }
                }else{
                    if(d+w<dp[v][1]){
                        dp[v][1]=d+w;
                        q.insert({d+w,v,1});
                    }
                }

            }
        }
        cout<<min(dp[n-1][1],dp[n-1][0])<<endl;
    }
    return 0;
}
