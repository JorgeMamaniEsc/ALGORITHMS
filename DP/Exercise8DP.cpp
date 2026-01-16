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

const int mx=5e5+5;
const int MOD=1e9+7;
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
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ini();
    int tt=1;
    //cin>>tt;
    while(tt--){
        int n;cin>>n;
        int s=n*(n+1)/2;
        if(s%2){
            cout<<0<<endl;
            continue;
        }
        s/=2;
        vi dp(s+1,0);
        dp[0]=1;
        f(i,1,n+1,1){
            vi ndp=dp;
            f(j,0,s+1,1) if(i+j<=s) ndp[i+j]=(ndp[i+j]+dp[j])%MOD;
            dp=ndp;
        }
        cout<<(dp[s]*modPow(2,MOD-2,MOD)+MOD)%MOD<<endl;
    }
    return 0;
}
