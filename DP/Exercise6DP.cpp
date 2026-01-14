#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//#define int long long
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
bool dp[1000001][101];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,ans=0;cin>>n;
        vi v(n),dd;
        dp[0][0]=true;

        f(i,0,n,1) cin>>v[i];
        f(i,1,1e6+1,1) {
            //dp[i][0]=true;
            bool ok=false;
            f(j,0,n,1) {
                dp[0][j]=true;
                if(ok) dp[i][j+1]=true;
                else if(i-v[j]>=0&&dp[i-v[j]][j]) {
                    dp[i][j+1]=true;
                    ans++;
                    dd.pb(i);
                    ok=true;
                }
            }
        }
        cout<<ans<<endl;
        for(int x:dd)cout<<x<<" ";

    }
    return 0;
}
