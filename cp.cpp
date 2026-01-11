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


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    while(tt--){
        int n,ans1=0,ans2=0;cin>>n;
        string s;cin>>s;
        vi aa,bb;
        f(i,0,n,1){
            if(s[i]=='b') bb.pb(i);
            else aa.pb(i);
        }
        f(i,0,sz(bb),1) bb[i]-=i;
        f(i,0,sz(aa),1) aa[i]-=i;
        int mb=bb[sz(bb)/2];
        int ma=aa[sz(aa)/2];
        f(i,0,sz(bb),1) ans1+=abs(bb[i]-mb);
        f(i,0,sz(aa),1) ans2+=abs(aa[i]-ma);
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}
