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

//RECORDAR IDENTIDAD DE BEZOUT
//PARA CADA GCD(A,B) HAY UNA COMBINACION LINEAL DE A Y B, QUE RESULTA SU CGD
//EJEMPLO GCD(55,80) = 5
//UNA COMBINACION LINEAL  ES 55*3 + 80*(-2) = 5

//DENOTAMOS G COMO EL GCD(A,B)
//SABEMOS QUE PODEMOS CAMBIAR DE GCD(A,B) A (GCD(B,A MOD B))
//ENTONCES TENEMOS X1 Y1 PARA SU COMBINACION LINEAL B*X1+(A MOD B)*Y1=G
//Y QUEREMOS ENCONTRAR X Y PARA EL GCD(A,B) 
//QUE ES A*X+B*Y=G
//A MOD B = A-FLOOR(A/B)*B
//SUSTITUIMOS ESO EN LA ECUACION ANTERIOR 
//G=B*X1+(A MOD B)*Y1=B*X1+(A-FLOOR(A/B)*B)*Y1
//REORDENAMOS
//G=A*Y1+B*(X1-Y1*FLOOR(A/B))
//X=Y1
//Y=X1-Y1*FLOOR(A/B)

//IMPLEMENTACION

//version recursiva
int gcd_xr(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=gcd_xr(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

//version iterativa
int gcd_x(int a,int b,int &x,int &y){
    x=1,y=0;
    int x1=0,y1=1a1=a,b1=b;
    while(b1){
        int q=a1/b1;
        tie(x,x1)=make_tuple(x1,x-q*x1);
        tie(y,y1)=make_tuple(y1,y-q*y1);
        tie(a1,b1)=make_tuple(b1,a1-q*b1);
    }
    return a1;
}

