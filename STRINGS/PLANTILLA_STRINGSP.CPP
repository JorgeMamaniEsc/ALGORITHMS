#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//#define int long long
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

const pii no={-1,-1};

int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}
int sgn(int x){
    if(x==0) return 0;
    return (x<0?-1:1);
}
bool choque(pii a,pii b){
    if(a>b) swap(a,b);
    auto [l1,r1]=a;
    auto [l2,r2]=b;
    if(r1>=l2) return true;
    return false;
}



//KMP para encontrar la longitud del prefijo propio mas largo que tambien es sufijo para cada subcadena s[0...i]
vi dame_kmp(string &s){
    int n=sz(s);
    vi kmp(n,0);
    f(i,1,n,1){
        int j=kmp[i-1];
        while(j>0&&s[i]!=s[j]) j=kmp[j-1];
        if(s[i]==s[j])j++;
        kmp[i]=j;
    }
    return kmp;
}

//Z para la longitud del prefijo mas largo de s[i...n-1] que tambien es prefijo de toda la cadena s
vi dame_z(string &s){
    int n=sz(s),l=0,r=0;
    vi z(n,0);
    f(i,1,n,1){
        if(i<=r) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

//string hashing
struct Hash{
    const int b1=313,b2=317,m1=1000000007,m2=1000000009;
    vi h1,h2,p1,p2;
    Hash(string &s){
        int n=sz(s);
        h1.assign(n+1,0);
        h2.assign(n+1,0);
        p1.assign(n+1,1);
        p2.assign(n+1,1);
        f(i,0,n,1){
            h1[i+1]=(h1[i]*b1+s[i])%m1;
            h2[i+1]=(h2[i]*b2+s[i])%m2;
            p1[i+1]=(p1[i]*b1)%m1;
            p2[i+1]=(p2[i]*b2)%m2;
        }
    }

    pii get_hash(int l,int r){
        int hash1=(h1[r+1]-h1[l]*p1[r-l+1])%m1,hash2=(h2[r+1]-h2[l]*p2[r-l+1])%m2;
        if(hash1<0) hash1+=m1;
        if(hash2<0) hash2+=m2;
        return {hash1,hash2};
    }

};
bool esPal(int l,int r,Hash &hs,Hash &hr,int n){
    return hs.get_hash(l,r)==hr.get_hash(n-1-r,n-1-l);
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    while(tt--){

    }
    return 0;
}
