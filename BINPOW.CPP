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


//EXPO BINARIA

//VERSION RECURSIVA
int binPow(int a,int b){
    if(b==0) return 1;
    int res=binPow(a,b/2);
    if(b%2) return res*res*a;
    return res*res;
}

//VERSION NORMALITA(RECOMENDADA)
int binPow1(int a,int b){
    int res=0;
    while(b>0){
        if(b&1) res=res*a;
        a=a*a;
        b>>=1; //esto es igual a b/=2
    }
    return res;
}


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

    //ME DA FLOJERA BORRAR EL MAIN
    return 0;
}
