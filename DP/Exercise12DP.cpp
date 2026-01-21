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

const int MOD=1e9+7;
const int inf=1e9;

int mp(int b,int e){
    int ans=1;
    while(e>0){
        if(e&1) ans=(ans*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return ans;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vector<vvi> dp(m+1,vvi(n+1,vi((1<<n),0)));
        dp[0][n][0]=1;
        f(i,1,m+1,1){
            f(mask,0,(1<<n),1) dp[i][0][mask]=dp[i-1][n][mask];
            f(j,1,n+1,1){
                f(mask,0,(1<<n),1){
                    bool ok=(1<<j-1)&mask;
                    if(ok) dp[i][j][mask]+=dp[i][j-1][mask-(1<<j-1)];
                    else{
                        dp[i][j][mask]+=dp[i][j-1][mask+(1<<j-1)];
                        if(j>1&&!((1<<j-2)&mask)) dp[i][j][mask]+=dp[i][j-2][mask];
                    }
                    dp[i][j][mask]%=MOD;
                }
            }
        }
        cout<<(dp[m][n][0]+MOD)%MOD;
    }
    return 0;
}
