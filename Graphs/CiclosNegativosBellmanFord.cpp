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
const int MOD=1000000007;
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
    int u,v,w;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vector<Node> node(m);
        f(i,0,m,1){
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            node[i]={a,b,c};
        }
        vi dist(n+1,0),parent(n+1,-1);
        int x;
        f(i,0,n,1){
            x=-1;
            for(auto [u,v,w]:node){
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    x=v;
                    parent[v]=u;
                }
            }
        }
        if(x==-1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        f(i,0,n,1) x=parent[x];
        vi ans;
        int v=x;
        while(true){
            ans.pb(v);

            if(v==x&&sz(ans)>1) break;
            v=parent[v];
        }
        reverse(all(ans));
        for(int u:ans)cout<<u+1<<" ";
        cout<<endl;
    }
    return 0;
}
