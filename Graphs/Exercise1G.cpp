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


vi query(vi s){
    cout<<"? "<<sz(s);
    f(i,0,sz(s),1)cout<<" "<<s[i]+1;
    cout<<endl;
    cout.flush();
    int k;cin>>k;
    vi t(k);
    f(i,0,k,1) {
        cin>>t[i];
        t[i]--;
    }
    return t;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vi vis(n*n+1,n+1);
        bool ok=false;
        f(i,1,n+1,1){
            vi s;
            f(j,0,n*n+1,1) if(vis[j]==n+1) s.pb(j);

            vi t=query(s);
            if(sz(t)>n){
                cout<<"!";
                f(i,0,n+1,1) cout<<" "<<t[i]+1;
                cout<<endl;
                cout.flush();
                ok=true;
                break;
            }
            f(j,0,sz(t),1) vis[t[j]]=i;
        }
        if(ok) continue;
        vi res;
        int x=find(all(vis),n+1)-vis.begin();
        res.pb(x);
        rf(i,x-1,0,1){
            if(vis[i]==vis[x]-1){
                x=i;
                res.pb(x);
            }
        }
        reverse(all(res));
        cout<<"!";
        f(i,0,n+1,1) cout<<" "<<res[i]+1;
        cout<<endl;
        cout.flush();
    }
    return 0;
}
