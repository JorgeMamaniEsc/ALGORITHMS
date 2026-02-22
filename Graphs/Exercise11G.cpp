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
struct Node{
    int u,v,w;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vvi ady(n),rev(n);
        vector<Node> node(m);
        f(i,0,m,1){
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            node[i]={a,b,-c};
            ady[a].pb(b);
            rev[b].pb(a);
        }
        vb poder(n,false),poderrev(n,false);
        queue<int> q;
        q.push(0);
        poder[0]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:ady[u]){
                if(poder[v]) continue;
                poder[v]=true;
                q.push(v);
            }
        }
        q.push(n-1);
        poderrev[n-1]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:rev[u]){
                if(poderrev[v]) continue;
                poderrev[v]=true;
                q.push(v);
            }
        }
        vi dist(n,inf);
        dist[0]=0;
        f(i,0,n,1){
            bool ok=false;
            for(auto e:node){
                if(dist[e.u]<inf&&dist[e.u]+e.w<dist[e.v]){
                    dist[e.v]=dist[e.u]+e.w;
                    ok=true;
                    if(i==n-1&&poder[e.v]&&poderrev[e.v]){
                        cout<<-1<<endl;
                        return 0;
                    }
                }
            }
            if(!ok) break;
        }
        cout<<-dist[n-1]<<endl;
    }

    return 0;
}
