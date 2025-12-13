#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define f(i,a,b,c) for(int i=a;i<b;i+=c)
#define rf(i,a,b,c) for(int i=a;i>=b;i-=c)
#define vi vector<int>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define vp vector<pair<int,int>>
#define vvvp vector<vector<vp>>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define endl '\n'
#define i128 __int128
#define pii pair<int,int>
#define pi 3.14159265358979323846
#define sq2 (sqrt(2.0))
#define inf 1e18

//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//template <typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;



/*
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

struct chash{
    const uint64_t C=(2e18*acos((long double)-1)) + 71;
    const int RANDOM=rng();
    int operator()(int x) const{
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

template <class K,class V> using ht =gp_hash_table<K,V,chash>;
*/
const int MOD=1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;
    //cin>>tt;
    while(tt--){
        int n,x;cin>>n>>x;
        vi dp(x+1,1e9),c(n);
        f(i,0,n,1) cin>>c[i];
        dp[0]=0;
        f(i,1,x+1,1) f(j,0,n,1) if(i-c[j]>=0) dp[i]=min(dp[i],dp[i-c[j]]+1);
        cout<<(dp[x]==1e9?-1:dp[x]);
    }
    return 0;
}
