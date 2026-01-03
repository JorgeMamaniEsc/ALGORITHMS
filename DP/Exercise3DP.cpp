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

/*
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
*/

/*
const int mx=3e5+5;
const int MOD=998244353;
int fact[mx],inv[mx];

int modPow(int x,int y,int m){
    x%=m;
    int ans=1;
    while(y>0){
        if(y&1) ans=(ans*x)%m;
        x=(x*x)%m;
        y>>=1;
    }
    return ans;
}
void ini(){
    fact[0]=1;
    f(i,1,mx,1) fact[i]=(fact[i-1]*i)%MOD;
    inv[mx-1]=modPow(fact[mx-1],MOD-2,MOD);
    rf(i,mx-2,0,1) inv[i]=(inv[i+1]*(i+1))%MOD;
}

int com(int n,int k){
    if(k<0||k>n) return 0;
    int a=(inv[k]*inv[n-k])%MOD;
    return (fact[n]*a)%MOD;
}
int perm(int n, int k) {
    if (k<0||k>n) return 0;
    return (fact[n]*inv[n-k])%MOD;
}*/
int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vi a(n),b(m);
        f(i,0,n,1) cin>>a[i];
        f(i,0,m,1) cin>>b[i];
        vvi dp(n+1,vi(m+1));
        f(i,1,n+1,1){
            f(j,1,m+1,1){
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        vi ans;
        int i=n,j=m;
        while(i>0&&j>0){
            if(a[i-1]==b[j-1]){
                ans.pb(a[i-1]);
                i--;j--;
            }else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        reverse(all(ans));
        cout<<sz(ans)<<endl;
        f(i,0,sz(ans),1) cout<<ans[i]<<" ";
    }
    return 0;
}
