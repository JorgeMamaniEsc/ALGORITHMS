#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt;cin>>tt;
    //while(tt--){
        int n,k;cin>>n>>k;
        ordered_set ch;
        f(i,1,n+1,1) ch.insert(i);
        int i=0;
        while(!ch.empty()){
            i=(i+k)%sz(ch);
            cout<<*(ch.find_by_order(i))<<" ";
            ch.erase(*(ch.find_by_order(i)));
        }
    //}
        return 0;
}
