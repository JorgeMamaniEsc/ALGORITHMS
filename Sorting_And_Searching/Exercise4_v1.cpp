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




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int tt;cin>>tt;
    //while(tt--){

    int n,x;cin>>n>>x;
    vp v(n);
    f(i,0,n,1){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(all(v));
    f(i,0,n,1){
        f(j,i+1,n,1){
            int l=j+1,h=n-1;
            while(l<h){
                int p=v[i].first,q=v[j].first,r=v[l].first,s=v[h].first;
                if(p+q+r+s==x) {
                    cout<<v[i].second+1<<" "<<v[j].second+1<<" "<<v[l].second+1<<" "<<v[h].second+1;
                    return 0;
                }else if(p+q+r+s<x)l++;
                else h--;
            }
        }
    }

    cout<<"IMPOSSIBLE";
    //}
        return 0;
}
