// LUOGU_RID: 159732791
#include<bits/stdc++.h>
using namespace std;
template<class T1,class T2> bool cmax(T1& a,const T2& b){return a<b?a=b,1:0;}
template<class T1,class T2> bool cmin(T1& a,const T2& b){return b<a?a=b,1:0;}
#define fir(i,x,y,...) for(int i(x),##__VA_ARGS__;i<=(y);i++)
#define firr(i,x,y,...) for(int i(x),##__VA_ARGS__;i>=(y);i--)
#define fird(i,x,y,d,...) for(int i(x),##__VA_ARGS__;i<=(y);i+=(d))
#define firrd(i,x,y,d,...) for(int i(x),##__VA_ARGS__;i>=(y);i-=(d))
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define endl "\n"
#define ll long long
#define ull unsigned long long
int T;
bool _mul=1;
ll gcd(ll x,ll y){if(!y) return x;return gcd(y,x%y);}
ll power(ll b,ll p,ll mod){ll res=1;while(p){if(p&1) res=res*b%mod;b=b*b%mod;p>>=1;}return res;}
const int N=2e5+5;
int n;
char a[N];
void solve()
{
    int p1=0,p2=0,c1=0,c2=0,c3=0,c4=0;
    cin>>n>>(a+1);
    fir(i,1,n)
    {
        if(a[i]=='N') p1++,c1++;
        else if(a[i]=='S') p1--,c1++;
        else if(a[i]=='W') p2++,c2++;
        else p2--,c2++;
    }
    if(p1%2!=0||p2%2!=0||(!c1&&!p2&&n==2)||(!c2&&!p1&&n==2))
    {
        NO;
        return;
    }
    c1=c2=c3=c4=0;
    fir(i,1,n)
    {
        if(a[i]=='N')
        {
            c1++;
            if(!p1&&c1==1) cout<<"H";
            else if(p1<0||c1>p1/2) cout<<"R";
            else cout<<"H";
        }
        else if(a[i]=='S')
        {
            c3++;
            if(!p1&&c3==1) cout<<"H";
            else if(p1>0||c3>-p1/2) cout<<"R";
            else cout<<"H";
        }
        else if(a[i]=='W')
        {
            c2++;
            if(!p2&&c2==1) cout<<"R";
            else if(p2<0||c2>p2/2) cout<<"H";
            else cout<<"R";
        }
        else
        {
            c4++;
            if(!p2&&c4==1) cout<<"R";
            else if(p2>0||c4>-p2/2) cout<<"H";
            else cout<<"R";
        }
    }
    cout<<endl;
    return;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    if(_mul) cin>>T;
    else T=1;
    while(T--) solve();
    return 0;
}