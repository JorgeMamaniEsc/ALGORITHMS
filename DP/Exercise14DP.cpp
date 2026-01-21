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

struct BIT{
    vi tree;
    int n;

    void ini(int nn){
        n=nn;
        tree.assign(n+1,0);
    }

    void upd(int i,int x){
        for(;i<=n;i+=(i&-i)){
            tree[i]=(tree[i]+x)%MOD;
        }
    }

    int qry(int i){
        int ans=0;
        for(;i;i-=(i&-i)){
            ans=(ans+tree[i])%MOD;
        }
        return ans;
    }

};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,k=0;cin>>n;
        map<int,int> m;
        vi v(n);
        f(i,0,n,1){
            cin>>v[i];
            m[v[i]]++;
        }
        BIT dp;
        dp.ini(n+5);
        for(auto &[x,cnt]:m) cnt=++k;
        f(i,0,n,1) v[i]=m[v[i]];
        int ans=0;
        f(i,0,n,1){
            int x=v[i];
            int t=1+dp.qry(x-1);
            ans=(ans+t)%MOD;
            dp.upd(x,t);
        }
        cout<<ans<<endl;
    }
    return 0;
}
