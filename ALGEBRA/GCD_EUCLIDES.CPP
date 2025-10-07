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
const int MOD = 1000000007;


//GCD DE EUCLIDES, EN C++17 PARA ADELANTE YA ES FUNCION ESTANDAR, SU COMPLEJIDAD ES LOG(MIN(A,B))

//version recursiva
int gcd_er(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

//version normal
int gcd_nr(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

//LCM
int lcm_n(int a,int b){
    return a/gcd_nr(a,b)*b;
}

//GCD BINARIO, AUN MAS OPTIMIZADO, TAMBIEN YA LO TIENEN C++17 PARA ADELANTE
//ES MAS RAPIDO PORQUE EL OPERADOR % ES MAS LENTO QUE LOS CLASICOS
int gcd_op(int a, int b){
    if(!a||!b) return a|b;
    unsigned shift=__builtin_ctz(a|b);
    a>>=__builtin_ctz(a);
    do{
        b>>=__builtin_ctz(b);
        if(a>b) swap(a,b);
        b-=a;
    }while(b);
    return a<<shift;
}
//__builtin_ctz(x) es los ceros al final de la representacion binaria de x 
//por ejemplo en 12(1100) y 20(10100) en ambos seria 2