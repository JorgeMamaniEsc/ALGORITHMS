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
#define INF (int)1e9

//PROPIEDADES DE LOS NUMEROS DE FIBONACCI

//IDENTIDAD DE CASSINI
//ESTA NOS DICE QUE F(N-1)*F(N+1)-F(N)*F(N)=(-1)**N
//DEMOSTRACION POR INDUCCION
//CASO BASE  N=1, F0*F2-F1*F1=0*1-1*1=-1
//HIPOTESIS  F(N-1)*F(N+1)-F(N)*F(N)=(-1)**N
//INDUCCION F(N)*F(N+2)-F(N+1)*F(N+1)=?
//F(N+2)=F(N+1)+F(N),F(N)*F(N+2)-F(N+1)*F(N+1)=f(N)*F(N+1)+F(N)*F(N)-F(N+1)*F(N+1)=
//F(N)*F(N)-F(N+1)*F(N+1)+F(N)*F(N+1)=F(N)*F(N)-F(N+1)*(F(N+1)-F(N))=F(N)*F(N)-F(N+1)*F(N-1)=-(-1)**N=(-1)**(N+1)
//QUEDA DEMOSTRADO

//REGLA DE LA SUMA
//F(N+K)=F(K)*F(N+1)+F(K-1)*F(N)
//SI LE DAMOS A K=N
//F(2N)=F(N)*(F(N+1)+F(N-1))

//IDENTIDAD DE MCD
//GCD(F(M),F(N))=F(GCD(M,N))
//RECORDAR QUE F(K)|F(N*K) PARA TODO N>=1, OSEA QUE F(K) DIVIDE A TODOS LOS MULTIPLOS DE SU INDICE


//CODIFICACION DE FIBONACCI

//PRIMERO RECORDEMOS UN TEOREMA
//TEOREMA DE ZECKENDORF
//TODO NUMERO POSITIVO N PUEDE ESCRIBIRSE DE MANERA UNICA COMO SUMA DE NUMEROS DE FIBONACCI NO CONSECUTIVOS
//ES DECIR EXISTE UN CONJUNTO DE INDICES I1>I2>...>IK
//TAL QUE N=F(I1)+F(I2)+...+F(IK),F(IJ)YF(IJ+1) NO SON CONSECUTIVOS EN LA SERIE


//DE AHI PODEMOS DEDUCIR QUE CUALQUIER NUMERO PUEDE CODIFICARSE DE UNA MANERA UNICA SEGUN EL CODIGO DE FIBONACCI
//PODEMOS REPRESENTAR EL CIFRADO CON CODIGOS BINARIOS (D0,D1,D2,...DS,1), 
//DONDE DI ES 1 SI F(I+2) SE UTILIZA EN LA REPRESENTACION
//AL FINAL SE LE AÑADE UN 1, PARA INDICAR EL FINAL DE LA PALABRA CLAVE, 
//ENTIENDA QUE ESTA ES LA UNICA VEZ QUE APARECEN 2 BITS 1 CONSECUTIVOS
//EJEMPLOS:
//1=1=F(2)=(11)F
//2=2=F(3)=(011)F
//6=5+1=F(5)+F(2)=(10011)F
//8=8=F(6)=(000011)F
//9=8+1=F(6)+F(2)=(100011)F
//19=13+5+1=F(7)+F(5)+F(2)=(1001011)F

//LA CODIFICACION SE HACE CON UN GREEDY SIMPLE
//1. RECORRE LOS NUMEROS DE FIBONACCI DESDE EL MAS GRANDE HASTA EL MAS PEQUEÑO 
//HASTA ENCONTRAR UNO MENOR O IGUAL A N
//2. SUPONGAMOS QUE ESTE NUMERO FUERA F(I), RESTAR F(I) DE N Y PONER 1 EN EL I-2 POSICION DEL CIFRADO
//3. REPETIR HASTA QUE NO QUEDE NADA
//4. AÑADIR UN 1 FINAL AL CIFRADO PARA INDICAR SU FINAL

//PARA DECODIFICAR, PRIMERO ELIMINE EL ULTIMO 1, DSPS SOLO SUME F(I+2) AL NUMERO


//FORMA MATRICIAL
//[1 1]*[F(N)]     [F(N)+F(N+1)]    [F(N+1)]
//[1 0] [F(N+1)] = [F(N)]          =[F(N)]

//DE AHI PODEMOS TRATAR LA ITERACION DE LA RECURRENCIA COMO UNA MULTIPLICACION REPETIDA DE MATRICES
//[1 1]**N    *      [F(1)]      =     [F(N+1)]
//[1 0]              [F(0)]      =     [F(N)]
//
//DONDE F1=1, F0=0
//[1 1] [F2 F1]
//[1 0]=[F1 F0]
//UTILIZAMOS LA MATRIZ
//[1 1]**N  [F(N+1) F(N)]
//[1 0]    =[F(N)   F(N-1)]


//IMPLEMENTACION
struct matrix {
    int mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
              }
          }
        }
        return c;
    }
};
matrix matpow(matrix base,int n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}

int fib(int n) {
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    return matpow(base, n).mat[0][1];
}

//METODO DOBLE RAPIDO
//N=2*K
//[F(2*K+1) F(2*K)  ]     [1 1]**2*K  [F(K+1) F(K)  ]**2
//[F(2*K)   F(2*K-1)]   = [1 0]    =  [F(K)   F(K-1)]

//ENCONTRAMOS:
//F(2*K+1)=F(K+1)**2 +F(K)**2
//F(2*K)=F(K)*(F(K+1)+F(K-1))=F(K)*(2*F(K+1)-F(K))
//PODEMOS CALCULAR F(N) Y F(N+1)

//IMPLEMENTACION
pair<int, int> fib1 (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib1(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

//PERIODIDAD MOD P
//LA SERIE DE FIBONACCI MOD P, SERA PERIODICA EN ALGUN PUNTO