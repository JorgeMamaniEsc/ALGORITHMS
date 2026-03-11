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

const int MOD=10000000000LL;
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

struct Order{
    int n,tam=0;
    vi bit;
    Order(int nn){
        n=nn;
        bit.assign(n+1,0);
    }
    void add(int i,int x){
        for(;i<=n;i+=(i&-i)) bit[i]+=x;
    }
    void insert(int x){
        add(x,1);
        tam++;
    }
    void erase(int x){
        add(x,-1);
        tam--;
    }
    int find(int k){
        int pos=0;
        for(int i=1<<(__lg(n)+1); i; i>>=1){
            if(pos+i<=n&&bit[pos+i]<=k){
                k-=bit[pos+i];
                pos+=i;
            }
        }
        return pos+1;
    }
    void erasek(int k){
        int x=find(k);
        erase(x);
    }
    bool empty(){
        return tam==0;
    }
};

//40284
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;//cin>>tt;
    while(tt--){
        int n,q;cin>>n>>q;
        Order tree(n);
        f(i,0,n,1){
            int x;cin>>x;
            tree.insert(x);
        }
        f(i,0,q,1){
            int x;cin>>x;
            if(x<0) tree.erasek(abs(x)-1);
            else tree.insert(x);
        }
        cout<<(tree.empty()?0:tree.find(0))<<endl;
    }
    return 0;
}
