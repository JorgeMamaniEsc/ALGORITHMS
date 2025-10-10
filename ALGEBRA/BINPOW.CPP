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
const int MOD=1e9+7;

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
    int res=1;
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


//APLICACION PARA PERMUTACIONES

//APLICAR PERMUTACION
vi app(vi s,vi p){
    vi ns(sz(s));
    f(i,0,sz(s),1) ns[i]=s[p[i]];
    return ns;
}

//LA PERMUTACION CON EXPO BINARIA
vi perm(vi s,vi p, int k){
    while(k>0){
        if(k&1) s=app(s,p);
        p=app(p,p);
        k>>=1;
    }
    return s;
}

//MULTIPLICACION DE MATRICES
vvi mMul(vvi &a,vvi &b){
    int m=sz(a);
    vvi c(m,vi(m,0));
    f(i,0,m,1){
        f(k,0,m,1){
            if(a[i][k]==0)continue ;
            int t=a[i][k];
            f(j,0,m,1){
                if(b[k][j]==0)continue;
                c[i][j]=(c[i][j]+t*b[k][j])%MOD;
            }
        }
    }
    return c;
}

 //EXPO BINARIA DE MATRICES
 vvi mPow(vvi b,int e){
    int m=sz(b);
    vvi r(m,vi(m,0));
    f(i,0,m,1) r[i][i]=1;
    while(e>0){
        if(e&1) r=mMul(r,b);
        b=mMul(b,b);
        e>>=1;
    }
    return r;
}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //ME DA FLOJERA BORRAR EL MAIN
    return 0;
}
