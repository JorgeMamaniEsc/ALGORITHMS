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

int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vs ma(n);
        pii a,b;
        vp dir={{1,0},{-1,0},{0,1},{0,-1}};
        f(i,0,n,1) cin>>ma[i];
        vector<vc> vis(n,vc(m,false));
        vvp dp(n,vp(m));
        f(i,0,n,1){
            f(j,0,m,1){
                if(ma[i][j]=='A') a={i,j};
                if(ma[i][j]=='B') b={i,j};
            }
        }
        queue<pii> q;
        q.push(a);
        vis[a.first][a.second]=true;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==b.first&&y==b.second) break;
            for(auto [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]&&ma[nx][ny]!='#'){
                    vis[nx][ny]=true;
                    dp[nx][ny]={x,y};
                    q.push({nx,ny});
                }
            }
        }
        if(!vis[b.first][b.second]){
            cout<<"NO";
            continue;
        }
        cout<<"YES"<<endl;
        string ans="";
        int x=b.first,y=b.second;
        while(x!=a.first||y!=a.second){
            auto [i,j]=dp[x][y];
            if(x>i) ans+="D";
            else if(x<i) ans+="U";
            else if(y<j) ans+="L";
            else ans+="R";
            x=i;
            y=j;
        }
        reverse(all(ans));
        cout<<sz(ans)<<endl<<ans;

    }


    return 0;
}
