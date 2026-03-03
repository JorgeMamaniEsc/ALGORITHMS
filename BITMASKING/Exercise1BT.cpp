#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define f(i,a,b,c) for(int i=a;i<b;i+=c)
#define rf(i,a,b,c) for(int i=a;i>=b;i-=c)
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<" ====================== "<<endl
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

//contar cuantos numeros tienen el bit i-esimo prendido de 0 a n;
int cnt(int n,int i){
    int cy=(1ll<<(i+1)),h=(1ll<<i);
    int to=(n+1)/cy,rem=(n+1)%cy;
    int ans=h*to;
    ans+=max(0ll,rem-h);
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    while(tt--){
        int l,r;cin>>l>>r;
        int bt=0,ans=inf;
        f(i,0,31,1) if(r&(1ll<<i)) bt=i;
        f(i,0,bt+1,1) ans=min(ans,r-l+1-(cnt(r,i)-cnt(l-1,i)));
        cout<<ans<<endl;
    }

    return 0;
}
