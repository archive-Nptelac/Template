#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a)  reverse(a.begin(),a.end())
#define all(a)  (a).begin(),(a).end()
#define vll vector<int>
#define pb push_back
#define mp make_pair
#define db double
#define mod 1000000007
#define pi 3.1415926535897932384626433832795028841971
#define INF 1e18
#define MAX 200005

int min(int a,int b){return a<b?a:b;}
int min(int a,int b,int c){a=min(a,b);a=min(a,c);return a;}
int max(int a,int b){return a>b?a:b;}
int max(int a,int b,int c){a=max(a,b);a=max(a,c);return a;}
int power(int a,int b){int res=1;while(b){if(b&1) res=res*a;a=a*a;b>>=1;}return res;}
int power(int a,int b,int m){if(b==0)   return 1;if(b==1)   return a%m;int res=1;a=a%m;while(b){if(b&1){res=(res*a)%m;}a=((a%m)*(a%m))%m;b>>=1;}return res;}
int Ceil(int a,int b){int res=a/b;if(a%b!=0)    res++;return res;}

template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }

int dxx[]={1,1,0,-1,-1,-1,0,1};
int dyy[]={0,1,1,1,0,-1,-1,-1};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

struct pll{
    int x,y;
};
bool comp(pll a,pll b){
    if(a.x==b.x)    return a.y<b.y;
    else    return a.x<b.x;
}

// find_by_order(k) : finds k-th element in the set
// order_of_key(k) : number of elements strictly lesser than k --> int

// cout << fixed << setprecision(10);

void solve(int the)
{
    char ch;
    db aa,bb,cc,dd,xx;
    string s1,s2,s3,s4,str;
    int i,j,a,b,c,d,n,k,m,l,r,x,y,z,low,high,mid,sum=0,ans=0,temp=0,t,q;
    


}















int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1,c=1;
    cin >> t;
    while(t--){
        // cout << "Case #" << c << ": ";
        solve(c);
        c++;
    }
    return 0;
}
/* UJJWAL KESHRI */
