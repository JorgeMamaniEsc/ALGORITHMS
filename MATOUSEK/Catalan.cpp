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

const int MOD=1000000007;
const int inf=10000000000000000;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};



//NUMEROS DE CATALAN
//Cuentan estructuras combinatorias recursivas donde el orden importa pero la estructura de agrupacion cambia,
//se denotan Cat0,Cat1,Cat2,...
//
//TABULACION PARA DARSE CUENTA RAPIDO
//N:   0 1 2 3 4  5  6
//Cat: 1 1 2 5 14 42 132
//
//USOS:
//Numero de formas de parentizar:
//a1+a2+...+an
//A u B u C ... u Z
//Expresiones binarias
//
//Usamos Cat(n-1)
//
//Secuencias de parentesis validos, numeros de strings balanceados con n pares
//Numero de arboles binarios con n nodos
//BSTs distintos con n claves
//Caminos de (0,0) a (n,n) sin cruzar la diagonal



int mp(int b,int e){
    int s=1;
    while(e>0){
        if(e&1) s=(s*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return s;
}

const int mx=3e5+5;
int fact[mx],inv[mx];
void ini(){
    fact[0]=1;
    f(i,1,mx,1) fact[i]=(fact[i-1]*i)%MOD;
    inv[mx-1]=mp(fact[mx-1],MOD-2);
    rf(i,mx-2,0,1) inv[i]=(inv[i+1]*(i+1))%MOD;
}
int com(int n,int k){
    if(k<0||k>n) return 0;
    int a=(inv[k]*inv[n-k])%MOD;
    return (fact[n]*a)%MOD;
}
int perm(int n, int k) {
    if (k<0||k>n) return 0;
    return (fact[n]*inv[n-k])%MOD;
}
int cat(int n){
    return com(2*n,n)*mp(n+1,MOD-2)%MOD;
}


//version dp
int precat(vi &cata){
    int n=sz(cata)-1;
    cata[0]=1;
    f(i,1,n+1,1){
        cata[i]=0;
        f(j,0,i,1) cata[i]=(cata[i]+cata[j]*cata[i-1-j]%MOD)%MOD;
    }
}





signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;cin>>tt;
    ini();
    while(tt--){
        //
    }

    return 0;
}
