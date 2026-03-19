#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define f(i,a,b,c) for(int i=a;i<b;i+=c)
#define rf(i,a,b,c) for(int i=a;i>=b;i-=c)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr<<" ====================== "<<endl
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
const ld eps=1e-9;
const int MOD=998244353;
const int inf=5000000000000000000;
int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


//numero de numeros <= a k que son coprimos con x, p son los divisores primos de x, usando principio de inclusion-exclusion
int copri(int k, vi &p){
    int ans=0;
    int n=sz(p);
    f(mask,0,(1<<n),1){
        int t=1;
        f(j,0,n,1){
            if(mask&(1<<j)) t*=p[j];
        }
        if(__builtin_popcountll(mask)&1) ans-=(k/t);
        else ans+=(k/t);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vi a(n);
        f(i,0,n,1) cin>>a[i];
        vi div;
        int xx=a[0];
        for(int i=2;i*i<=a[0];i++){
            if(xx%i) continue;
            div.pb(i);
            while(xx%i==0) xx/=i;
        }
        if(xx>1) div.pb(xx);
        int ans=1;
        f(i,1,n,1){
            int x=a[i-1]/a[i],l=m/a[i];
            if(a[i-1]%a[i]!=0){
                ans=0;
                break;
            }
            vi temp;
            for(int p:div) if(x%p==0) temp.pb(p);
            ans=(ans*copri(l,temp))%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
