//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1970
//El problema pide calcular n elevado a k
//sin generarlo completo: solo los 3 primeros dígitos (con logaritmos) y los 3 últimos dígitos (con exponenciación modular).
//La salida debe mostrarse como LLL...TTT para cada caso de prueba.

#include <bits/stdc++.h>
using namespace std;

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
#define vvp vector<vector<vp>>
#define endl '\n'
#define i128 __int128
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int>
#define PI 3.14159265358979323846
#define SQ2 (sqrt(2.0))

const int INF = LLONG_MAX;


//EXPO MODULAR (X ELEVADO Y) MOD N
int modPow(int x,int y,int n){
    x%=n;
    int res=1;
    while(y>0){
        if(y&1) res=(res*x)%n;
        x=x*x%n;
        y>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin>>tt;
    while(tt--){
        int n,k;cin>>n>>k;
        int t=modPow(n,k,1000);
        double x = k * log10(n);
        double f = x - floor(x);
        double d = pow(10, f + 2);

        int l = (int)d;
        cout << l << "...";
        cout << setw(3) << setfill('0') << t << "\n";

    }
    return 0;
}
