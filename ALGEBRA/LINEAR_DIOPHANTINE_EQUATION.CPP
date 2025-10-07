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

//LA ECUACION DIOFANCTICA LINEAL(EN 2 VARIABLES) ES UNA ECUACION DE LA FORMA GENERAL A*X+B*Y=C
//X Y SUELEN SER DESCONOCIDOS
//DE LA ECUACION PODEMOS SACAR:
//A*X ES CONGRUENTE A C (MOD B) 
//B*Y ES CONGRUENTE A C (MOD A)

//CUANDO B ES DIFERENTE DE 0, SI A Y B CON COPRIMOS, PODEMOS REPRESENTAR COMO
//X ES CONGRUENTE A C*(INVERSO MODULAR DE A MOD B)MOD B

//SI A Y B NO SON COMPRIMOS, LOS VALORES DE A*X MOD(B) PARA TODOS LOS ENTEROS X SON DIVISIBLES POR G(GCD(A,B))
//POR LO QUE LA SOLUCION SOLO EXISTE CUANDO C ES DIVISIBLE POR G.
//EN ESTE CASO, CADA SOLUCION SE PUEDE ENCONTRAR REDUCIENDO LA ECUACION POR G
//(A/G)*X=(C/G)*(MOD B/G)
//POR DEFINICION DE G,A/B Y B/G SON COPRIMOS, RECORDAR QUE G ES GCD
//LA SOLUCION SERIA
//X ES CONGRUENTE (C/G)(INVERSO MODULAR DE (A/G) MOD (B/G)) MOD (B/G)
//Y=(C-A*X)/B

//SOLUCION ALGORITMICA
//PODEMOS USAR LA IDENTIDAD DE BEZOUT PARA COMPRENDER LA SIGUIENTE SOLUCION
//SI G ES GCD DE A Y B, EXISTEN X Y TALQUE A*X+B*Y=G
//ADEMAS G ES EL MENOR ENTERO POSITIVO QUE SE PUEDE ESCRIBIR COMO A*X+B*Y
//TODOS LOS NUMEROS ENTEROS DE LA FORMA A*X+B*Y SON MULTIPLOS DE G

//ENTONCES PARA ENCONTRAR UNA SOLUCION A LA ECUACION DIOFANTICA CON 2 INCOGNITAS
//SE PUEDE USAR EL ALGORITMO EUCLIDIANO EXTENDIDO
//PRIMERO SUPONGAMOS QUE A Y B NO SON NEGATIVOS
//CUANDO APLICAMOS EL AEE PARA A Y B, ENCONTRAMOS SU GCD G Y 2 NUMEROS XG YG , TALQUE
//A*XG+B*YG=G
//SI C ES DIVISIBLE POR G, ENTONCES LA ECUACION DIOFANTICA TIENE SOLUCION, DE LO CONTRARIO NO TIENE
//DEMOSTRAR ESTO ES SENCILLO YA QUE SU COMBINACION LINEAL TIENE QUE SER DIVISIBLE POR SU DIVISOR EN COMUN

//AHORA SUPONGAMOS QUE C ES DIVISIBLE POR G, ENTONCES TENDRIAMOS
//A*XG*(C/G)+B*YG*(C/G)=C
//POR LO TANTO UNA DE LAS SOLUCIONES ES
//X0=XG*(C/G)
//Y0=YG*(C/G)

//RECORDEMOS QUE NO FUNCIONA PARA A=B=0

//IMPLEMENTACION

int gcd_x(int a,int b,int &x,int &y){
    x=1,y=0;
    int x1=0,y1=0,a1=a,b1=b;
    while(b1){
        int q=a1/b1;
        tie(x,x1)=make_tuple(x1,x-q*x1);
        tie(y,y1)=make_tuple(y1,y-q*y1);
        tie(a1,b1)=make_tuple(b1,a1-q*b1);
    }
    return a1;
}
//OBTENER UNA SOLUCION
bool find(int a,int b,int c,int &x0,int &y0,int &g){
    g=gcd_x(abs(a),abs(b),x0,y0);
    if(c%g) return false;
    x0*=c/g;
    y0*=c/g;
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}

//OBTERNER TODAS LAS SOLUCIONES
//TODAS LAS SOLUCIONES TIENEN LA FORMA
//X=X0+K*(B/G)
//Y=Y0-K*(A/G)

//ENCONTRAR EL NUMERO DE SOLUCIONES Y LAS SOLUCIONES EN UN INTERVALO DADO

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}