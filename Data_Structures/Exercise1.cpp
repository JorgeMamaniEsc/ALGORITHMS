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
#define inf 1e10

//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//se puede hacer con pair y map pero creo q es conveniente usar mas struct
struct rng{
    int l,r,idx;
    bool operator < (const rng &o) const{
        if(l==o.l) return r>o.r;
        return  l<o.l;
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt;cin>>tt;
    //while(tt--){
        int n;cin>>n;
        vector<rng> rg(n);
        vb c1(n),c2(n);
        f(i,0,n,1){
            cin>>rg[i].l;
            cin>>rg[i].r;
            rg[i].idx=i;
        }
        sort(all(rg));
        int mx=0;
        f(i,0,n,1){
            if(rg[i].r<=mx){
                c2[rg[i].idx]=true;
            }
            mx=max(mx,rg[i].r);
        }
        int mn=inf;
        rf(i,n-1,0,1){
            if(rg[i].r>=mn){
                c1[rg[i].idx]=true;
            }
            mn=min(mn,rg[i].r);
        }
        f(i,0,n,1) cout<<c1[i]<<" ";
        cout<<endl;
        f(i,0,n,1) cout<<c2[i]<<" ";

    //}
        return 0;
}
