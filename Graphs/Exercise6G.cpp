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
const int inf=1000000000000000;
int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}


bool bfs(int x,vi &color, vvi &ady){
    queue<int> q;
    q.push(x);
    color[x]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:ady[u]){
            if(color[v]==-1){
                color[v]=color[u]^1;
                q.push(v);
            }else if(color[v]==color[u]) return false;
        }
    }
    return true;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vvi ady(n);
        f(i,0,m,1){
            int l,r;cin>>l>>r;
            l--;r--;
            ady[l].pb(r);
            ady[r].pb(l);
        }
        vi color(n,-1);
        bool ok=false;
        f(i,0,n,1){
            if(color[i]!=-1) continue;
            if(!bfs(i,color,ady)){
                ok=true;
                break;
            }
        }
        if(ok) cout<<"IMPOSSIBLE";
        else{
            f(i,0,n,1) cout<<color[i]+1<<" ";
        }
    }


    return 0;
}
