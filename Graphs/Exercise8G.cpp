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

int sgn(int n){
    if(n==0) return 0;
    return (n<0?-1:1);
}

int g(string s,int l,int r){
    int ans=1;
    f(i,0,13,1){
        int c=s[i+l]-'0';
        ans*=c;
    }
    return ans;
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vs ma(n);
        f(i,0,n,1) cin>>ma[i];
        vi dist(n*m,-1),h(n*m,-1);
        vp p(n*m);
        queue<pii> q;
        pii start;
        f(i,0,n,1){
            f(j,0,m,1){
                if(ma[i][j]=='M'){
                    q.push({i,j});
                    dist[i*m+j]=0;
                }
                if(ma[i][j]=='A') start={i,j};
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            f(i,0,4,1){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m||dist[nx*m+ny]!=-1||ma[nx][ny]=='#') continue;
                q.push({nx,ny});
                dist[m*nx+ny]=dist[m*x+y]+1;
            }
        }
        q.push(start);
        pii fin={-1,-1};
        h[start.first*m+start.second]=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==0||y==0||x==n-1||y==m-1){
                fin={x,y};
                break;
            }
            f(i,0,4,1){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m||h[nx*m+ny]!=-1||ma[nx][ny]=='#') continue;
                h[nx*m+ny]=h[m*x+y]+1;
                if(dist[nx*m+ny]!=-1&&h[nx*m+ny]>=dist[nx*m+ny]) continue;
                q.push({nx,ny});
                p[m*nx+ny]={x,y};
            }
        }
        pii f={-1,-1};
        if(fin==f){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        string ans="";
        while(fin!=start){
            pii temp=p[fin.first*m+fin.second];
            if(temp.first>fin.first) ans+='U';
            else if(temp.first<fin.first) ans+='D';
            else if(temp.second>fin.second)ans +='L';
            else ans+='R';
            fin=temp;
        }
        reverse(all(ans));
        cout<<sz(ans)<<endl<<ans;
    }

    return 0;
}
