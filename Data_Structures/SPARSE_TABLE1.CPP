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

int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vb pr(101,true);

    int tt=1;//cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vi v(m),lg(m+1,0);
        f(i,0,m,1) cin>>v[i];
        int q;cin>>q;
        f(i,2,m+1,1) lg[i]=lg[i/2]+1;
        int log=lg[m]+1;
        vvi st(log,vi(m));
        f(i,0,m,1) st[0][i]=v[i];
        f(k,1,log,1) f(i,0,m+1-(1<<k),1) st[k][i]=max(st[k-1][i],st[k-1][i+(1<<(k-1))]);
        while(q--){
            int x1,y1,x2,y2,k;cin>>x1>>y1>>x2>>y2>>k;
            y1--;y2--;
            if(x1<=v[y1]||x2<=v[y2]){
                cout<<"NO"<<endl;
                continue;
            }
            if(abs(x2-x1)%k||abs(y2-y1)%k){
                cout<<"NO"<<endl;
                continue;
            }
            int mx=x1+((n-x1)/k)*k;
            if(y2<y1) swap(y1,y2);
            int l=lg[y2-y1+1];
            int gg=max(st[l][y1],st[l][y2-(1<<l)+1]);
            //cout<<mx<<" "<<gg<<endl;
            if(gg>=mx) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }


    return 0;
}
