#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

//using namespace __gnu_pbds;
#define int long long
#define rep(i,a,b,c) for(int i=a;i<b;i+=c)
#define nrep(i,a,b,c) for(int i=a;i>=b;i-=c)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr<<" ====================== "<<endl
#define vi vector<int>
#define vd vector<long double>
#define vvd vector<vd>
#define vvvd vector<vvd>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
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
#define vmp vector<map<int,int>>
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
	cout<<fixed;
    int tt=1;
    //cin>>tt;
    while(tt--){
        int n;cin>>n;
        vi izq(n),der(n);
        vc c1(n),c2(n,'?');
        rep(i,0,n,1){
            int a,b;char c;cin>>a>>b>>c;
            a--;b--;
            izq[i]=a;
            der[i]=b;
            c1[i]=c;
        }
        vb dir(n);
        auto f=[&]()->bool{
            nrep(i,n-1,0,1){
                int u=izq[i],v=der[i];
                if(u==-1) continue;
                char k1=c1[i],k2=c2[i],u1=c1[u],u2=c2[u],v1=c1[v],v2=c2[v];

                if(k2=='?'){
                    if(u1==k1||u2==k1||v1==k1||v2==k1) continue;
                    if(u2!='?'&&v2!='?') return false;
                    if(u2!='?'&&v1>k1) return false;
                    if(v2!='?'&&u1>k1) return false;
                    if(u2!='?'){
                        c2[v]=k1;
                        continue;
                    }
                    if(v2!='?'){
                        c2[u]=k1;
                        continue;
                    }
                    if(v1>k1&&u1>k1) return false;
                    bool b1=(u1<k1),b2=(v1<k1);
                    if((dir[i]&&b1)||(!dir[i]&&!b2)){
                        c2[u]=k1;
                    }else {
                        c2[v]=k1;
                    }
                    continue;
                }


                bool o1=(u1==k1||u2==k1||v1==k1||v2==k1),o2=(u1==k2||u2==k2||v1==k2||v2==k2);
                if(k1==k2&&o1&&o2){
                    int t=0;
                    if(u1==k1) t++;
                    if(v1==k1) t++;
                    if(u2==k1) t++;
                    if(v2==k1) t++;
                    if(t<2) o1=false;
                }
                if(o1&&o2) continue;
                if(!o1&&!o2&&(u2!='?'||v2!='?'))  return false;
                if(o1){
                    if(u2!='?'&&(v1>k2||u1!=k1)) return false;
                    if(v2!='?'&&(u1>k2||v1!=k1)) return false;

                    if(u2!='?'){
                        c2[v]=k2;
                        continue;
                    }
                    if(v2!='?'){
                        c2[u]=k2;
                        continue;
                    }
                    if(v1>k2&&u1>k2) return false;
                    bool b1=(u1<=k2&&v1==k1),b2=(v1<=k2&&u1==k1);
                    if(!b1&&!b2) return false;
                    if((dir[i]&&b1)||(!dir[i]&&!b2)){
                        c2[u]=k2;
                    }else {
                        c2[v]=k2;
                    }
                }else if(o2){
                    if(u2!='?'&&(v1>k1||u1!=k2)) return false;
                    if(v2!='?'&&(u1>k1||v1!=k2)) return false;
                    if(u2!='?'){
                        c2[v]=k1;
                        continue;
                    }
                    if(v2!='?'){
                        c2[u]=k1;
                        continue;
                    }
                    if(v1>k1&&u1>k1) return false;
                    bool b1=(u1<=k1&&v1==k2),b2=(v1<=k1&&u1==k2);
                    if(!b1&&!b2) return false;
                    if((dir[i]&&b1)||(!dir[i]&&!b2)){
                        c2[u]=k1;
                    }else {
                        c2[v]=k1;
                    }
                }else{
                    o1=(k1>=u1&&k2>=v1);o2=(k2>=u1&&k1>=v1);
                    if(!o1&&!o2) return false;
                    if((dir[i]&&o1)||(!dir[i]&&!o2)){
                        c2[u]=k1;
                        c2[v]=k2;
                    }else{
                        c2[u]=k2;
                        c2[v]=k1;
                    }
                }
            }
            return true;
        };
        bool aja=false;
        rep(mask,0,(1ll<<n),1){
            vc cc1=c1,cc2=c2;
            rep(i,0,n,1){
                if((1ll<<i)&mask) dir[i]=true;
                else dir[i]=false;
            }
            if(f()){
                aja=true;
                break;
            }
            c1=cc1;
            c2=cc2;
        }
        if(!aja){
            cout<<-1<<endl;
            continue;
        }
        rep(i,0,n,1){
            if(c2[i]=='?') c2[i]='t';
            cout<<c1[i]<<c2[i]<<endl;
        }
    }

    return 0;
}
