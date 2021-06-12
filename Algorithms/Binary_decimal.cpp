    
string binary(int n)
{
    string s="";
    if(n==0)    s="0";
    int a;
    while(n){
        a=n%2;n/=2;
        s.pb(a+'0');
    }
    int m=s.length();m=32-m;
    for(int i=0;i<m;i++)    s.pb('0');
    reverse(s.begin(),s.end());
    return s;
}

int decim(string s)
{
    int ans=0,a=1,n=s.length(),b,c;
    for(int i=n-1;i>=0;i--){
        b=s[i]-'0';
        c=a*b;ans+=c;a*=2;
    }
    return ans;
}

/*****************Right most set bit****************/

int rightmostsetbit(int n)
{
    if(n&1) return 0;
    n=(n^(n&(n-1)));
    int a=-1;
    while(n){
        n>>=1;
        a++;
    }
    return a;
}

/********************Count set bit******************/
int countset(int n)
{
    int a=0;
    while(n){
        a++;
        n=n&(n-1);
    }
    return a;
}
