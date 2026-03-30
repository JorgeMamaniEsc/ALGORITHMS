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

int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,m,k;cin>>n>>m>>k;
        vvp ady(n);
        vp llega;
        vector<multiset<int>> dp(n);
        multiset<pii> q;
        f(i,0,m,1){
            int a,b,x;cin>>a>>b>>x;
            a--;b--;
            ady[a].pb({b,x});
            if(b==n-1) llega.pb({a,x});
        }
        dp[0].insert(0);
        q.insert({0,0});
        while(!q.empty()){
            auto it=q.begin();
            auto [d,u]=*it;
            q.erase(it);
            if(sz(dp[u])==k&&d>*(prev(dp[u].end()))) continue;
            for(auto [v,w]:ady[u]){
                if(sz(dp[v])<k||d+w<(*(prev(dp[v].end())))){
                    if(sz(dp[v])==k) dp[v].erase(prev(dp[v].end()));
                    dp[v].insert(d+w);
                    q.insert({d+w,v});
                }
            }
        }
        multiset<int> ans;
        for(auto [u,w]:llega){
            for(int v:dp[u]){
                int kk=v+w;
                if(sz(ans)<k||kk<(*(prev(ans.end())))){
                    if(sz(ans)==k) ans.erase(prev(ans.end()));
                    ans.insert(kk);
                }
            }
        }
        for(int x:ans)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
