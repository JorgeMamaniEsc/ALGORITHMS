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

const int MOD=998244353;
const int inf=1000000000000000;
int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}

int sgn(int n){
    if(n==0) return 0;
    return (n<0?-1:1);
}

struct Node{
    int next[26];
    int cnt;
    Node(){
        f(i,0,26,1) next[i]=-1;
        cnt=0;
    }
};

struct Trie{
    vector<Node> nodes;
    Trie(){
        nodes.pb(Node());
    }
    void insert(string &s){
        int u=0;
        f(i,0,sz(s),1){
            int c=s[i]-'a';
            if(nodes[u].next[c]==-1){
                nodes[u].next[c]=sz(nodes);
                nodes.pb(Node());
            }
            u=nodes[u].next[c];
            nodes[u].cnt++;
        }
    }
    int qry(string &s){
        int u=0,t=0;
        rf(i,sz(s)-1,0,1){
            int c=s[i]-'a';
            if(nodes[u].next[c]==-1) break;
            u=nodes[u].next[c];
            t+=nodes[u].cnt;
        }
        return t;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;//cin>>tt;
    while(tt--){
        Trie tree;
        int n;cin>>n;
        int ans=0;
        vs v(n);
        f(i,0,n,1){
            cin>>v[i];
            ans+=sz(v[i]);
            tree.insert(v[i]);
        }
        ans=ans*2ll*n;
        f(i,0,n,1) ans-=2ll*(tree.qry(v[i]));
        cout<<ans<<endl;
    }

    return 0;
}
