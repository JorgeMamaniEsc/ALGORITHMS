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

const int MOD=1e9+7;
const int inf=1e9;

int mp(int b,int e){
    int ans=1;
    while(e>0){
        if(e&1) ans=(ans*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return ans;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int l,r;cin>>l>>r;
        if(r==0){
            cout<<1;
            continue;
        }
        l--;
        vvi dp(20,vi(11,0));
        f(i,0,10,1) dp[1][i]=1;
        dp[1][10]=10;
        f(i,2,19,1){
            f(j,0,10,1){
                dp[i][j]=dp[i-1][10]-dp[i-1][j];
                dp[i][10]+=dp[i][j];
            }
            //cout<<dp[i][10]<<endl;
        }
        auto g=[&](int num) -> int{
            if(num<0) return 0;
            if(num==0) return 1;
            string s=to_string(num);
            int n=sz(s),ans=0;
            f(len,1,n,1){
                if(len==1) ans+=10;
                else f(j,1,10,1) ans+=dp[len][j];
            }
            int last=-1;
            bool ok=true;
            f(i,0,n,1){
                int lt=s[i]-'0';
                int start=((i==0&&n>1)?1:0);
                f(d,start,lt,1){
                    if(d!=last) ans+=dp[n-i][d];
                }
                if(lt==last){
                    ok=false;
                    break;
                }
                last=lt;
            }
            if(ok) ans++;
            return ans;
        };
        cout<<g(r)-g(l);

    }
    return 0;
}
