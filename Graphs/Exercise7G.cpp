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

pii bfs(int x,vi &parent,vb &vis,vvi &ady){
    queue<int> q;
    vis[x]=true;
    q.push(x);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:ady[u]){
            if(!vis[v]){
                parent[v]=u;
                vis[v]=true;
                q.push(v);
            }else if(parent[u]!=v){
                //parent[v]=u;
                return {u,v};
            }
        }
    }
    return {-1,-1};
}

bool dfs(int ch,int par,vb &vis, vvi &ady,vi &cy){
    vis[ch]=true;
    for(int u:ady[ch]){
        cy.pb(u);
        if(!vis[u]){
            if(dfs(u,ch,vis,ady,cy)) return true;
        }
        else if(u!=par) return true;
        cy.pop_back();
    }
    return false;
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
        vi cycle;
        vb vis(n,false);
        f(i,0,n,1){
            cycle.pb(i);
            if(!vis[i]&&dfs(i,-1,vis,ady,cycle)){
                vi ans={*cycle.rbegin()};
                for(auto j=cycle.rbegin()+1;j!=cycle.rend();j++){
                    ans.pb(*j);
                    if(*j==*cycle.rbegin()) break;
                }
                cout<<sz(ans)<<endl;
                for(int i:ans)cout<<i+1<<" ";
                return 0;
            }
            cycle.pop_back();
        }
        cout<<"IMPOSSIBLE";
    }


    return 0;
}
