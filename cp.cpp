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

    bool unite(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(tam[a]<tam[b]) swap(a,b);
        parent[b]=a;
        tam[a]+=tam[b];
        return true;
    }

    int size(int x){
        return tam[find(x)];
    }
};


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    vi dir={-1,0,1};
    while(tt--){
        int n,m;cin>>n>>m;
        vs ma(n);
        f(i,0,n,1) cin>>ma[i];
        DSU dsu(n*m);
        f(i,0,n,1){
            f(j,0,m,1){
                if(ma[i][j]!='#') continue;
                int u=i*m+j;
                if(i+1<n && ma[i+1][j]=='#') dsu.unite(u,(i+1)*m+j);
                if(j+1<m && ma[i][j+1]=='#') dsu.unite(u,i*m+j+1);
            }
        }
        int mx=0;
        f(r,0,n,1){
            set<int> vis;
            int t=0;
            f(c,0,m,1){
                for(int &dr:dir){
                    int nr=r+dr;
                    if(nr<0||nr>=n) continue;
                    if(ma[nr][c]=='#'){
                        int comp=dsu.find(nr*m+c);
                        if(!vis.count(comp)){
                            vis.insert(comp);
                            t+=dsu.tam[comp];
                        }
                    }
                }
                if(ma[r][c]=='.') t++;
            }
            mx=max(mx,t);
        }
        f(c,0,m,1){
            set<int> vis;
            int t=0;
            f(r,0,n,1){
                for(int &dc:dir){
                    int nc=c+dc;
                    if(nc<0||nc>=m) continue;
                    if(ma[r][nc]=='#'){
                        int comp=dsu.find(r*m+nc);
                        if(!vis.count(comp)){
                            vis.insert(comp);
                            t+=dsu.tam[comp];
                        }
                    }
                }
                if(ma[r][c]=='.') t++;
            }
            mx=max(mx,t);
        }
        cout<<mx<<endl;
    }
    return 0;
}
