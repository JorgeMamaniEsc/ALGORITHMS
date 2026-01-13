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
const int inf=1e15;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n;cin>>n;
        vs ma(n);
        f(i,0,n,1) cin>>ma[i];
        vb vis(n*n,false);
        cout<<ma[0][0];
        vp q={{0,0}};
        f(k,0,2*n-2,1){
            vp nq;
            char mn='Z';
            for(auto &[i,j]:q){
                int p=i*n+j;
                if(!vis[p]){
                    vis[p]=true;
                    if(i<n-1&&ma[i+1][j]<=mn){
                        if(ma[i+1][j]<mn) nq.clear();
                        mn=ma[i+1][j];
                        nq.pb({i+1,j});
                    }
                    if(j<n-1&&ma[i][j+1]<=mn){
                        if(ma[i][j+1]<mn) nq.clear();
                        mn=ma[i][j+1];
                        nq.pb({i,j+1});
                    }
                }
            }
            q=nq;
            cout<<mn;
        }
    }
    return 0;
}
