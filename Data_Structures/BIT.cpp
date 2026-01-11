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
const int MOD=998244353;
int bp(int b,int e){

    int ans=1;
    while(e>0){
        if(e&1) ans=(ans*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return ans;
}

struct BIT{
    int n;
    vi tree;

    void ini(int nn){
        n=nn;
        tree.assign(n+1,0);
    }

    void add(int i,int val){
        for(;i<=n;i+=i&-i) tree[i]+=val;
    }

    int qry(int i){
        int s=0;
        for(;i>0;i-=i&-i) s+=tree[i];
        return s;
    }
    int qry(int l,int r){
        if(l>r) return 0;
        return qry(r)-qry(l-1);
    }
};

struct miku{
    int val,l,r,m;
    bool operator<(const miku &o) const{
        return val<o.val;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    while(tt--){
        int n,ans=0;cin>>n;
        vi a(n+1),b(n+1);
        f(i,1,n+1,1) cin>>a[i];
        f(i,1,n+1,1) cin>>b[i];
        vi ll(n+1),rr(n+1),st;
        f(i,1,n+1,1){
            while(!st.empty()&&a[st.back()]<a[i]) st.pop_back();
            ll[i]=(st.empty()?0:st.back());
            st.pb(i);
        }
        st.clear();
        rf(i,n,1,1){
            while(!st.empty()&&a[st.back()]<=a[i]) st.pop_back();
            rr[i]=(st.empty()?n+1:st.back());
            st.pb(i);
        }
        vector<miku> qq;
        vp upd;
        f(i,1,n+1,1){
            if(a[i]==b[i]) ans+=(i-ll[i])*(n-i+1);
            if(i+1<rr[i]) qq.pb({a[i],i+1,rr[i]-1,i-ll[i]});
            upd.pb({b[i],i});
        }
        sort(all(qq));
        sort(all(upd));
        BIT bit;
        bit.ini(n);
        int j=0;
        for(auto &k:qq){
            while(j<sz(upd)&&upd[j].first<=k.val){
                int i=upd[j].second;
                bit.add(i,n-i+1);
                j++;
            }
            int ts=bit.qry(k.l,k.r);
            ans+=k.m*ts;
        }
        cout<<ans<<endl;
    }
    return 0;
}
