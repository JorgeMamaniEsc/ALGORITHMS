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

const int MOD=10000000000LL;
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    vi mn(1000+1,inf);
    mn[0]=0;
    mn[1]=0;
    f(i,1,1001,1){
        f(k,1,i+1,1){
            int x=i/k;
            if(i+x<=1000) mn[i+x]=min(mn[i+x],mn[i]+1);
        }
    }
    //cout<<*max_element(all(mn))<<endl;
    while(tt--){
        int n,k;cin>>n>>k;
        vi b(n),c(n);
        f(i,0,n,1){
            cin>>b[i];
            b[i]=mn[b[i]];

        }
        f(i,0,n,1) cin>>c[i];
        k=min(k,12000ll);
        vi dp(k+1,0);
        f(i,0,n,1){
            vi ndp=dp;
            f(j,0,k+1,1) {
                if(j+b[i]<=k) ndp[j+b[i]]=max(ndp[j+b[i]],dp[j]+c[i]);
            }
            dp=ndp;
        }
        cout<<*max_element(all(dp))<<endl;
    }
    return 0;
}
