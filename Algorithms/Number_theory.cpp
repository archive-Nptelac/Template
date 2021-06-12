/************************Sieve***********************/

vector<bool>is_prime(MAX,true);
void sieve(){
    int i,j;
    is_prime[0]=false;
    is_prime[1]=false;
    for(i=2;i<MAX;i++){
        if(is_prime[i]){
            for(j=i*i;j<MAX;j+=i){
                is_prime[j]=false;
            }
        }
    }
}


/***************** Segmented Sieve *****************/

vector<int>prime     // store prime number [0,MAX] using normal sieve
vector<int> segmented_sieve(int l,int r){
    if(l==1)    l=2;
    int d=r-l+1;
    vector<bool>is_prime1(d+5,true);
    for(int i=0;prime[i]*prime[i]<=r;i++){
        int x=prime[i];
        int first=(l/x)*x;
        if(first<l) first+=x;
        for(int j=first;j<=r;j+=x){
            is_prime1[j-l]=false;
        }
        if(first==x)    is_prime1[first-l]=true;
    }
    vector<int>ans;
    for(int i=l;i<=r;i++){
        if(is_prime1[i-l])  ans.pb(i);
    }
    return ans;
}


/*************************SPF*********************/

vector<int>spf(MAX);
void SPF()
{
    int i,j;
    spf[0]=1;
    for(i=1;i<MAX;i++)  spf[i]=i;
    for(i=2;i<MAX;i++){
        if(spf[i]==i){
            for(j=i*i;j<MAX;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }
}


/*************************ETF************************/

vector<int>etf(MAX);
void ETF()
{
    int i,j;
    for(i=0;i<MAX;i++)  etf[i]=i;
    for(i=2;i<MAX;i++){
        if(etf[i]==i){
            for(j=i;j<MAX;j+=i){
                etf[j]=etf[j]-(etf[j]/i);
            }
        }
    }
}

int phi(int n)
{
    int ans=n,i;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            ans-=(ans/i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) ans-=(ans/n);
    return ans;
}


/****************** GCD and LCM **********************/

int gcd(int a,int b)
{
    if(b==0)    return a;
    if(a==0)    return b;
    if(a>=b)    return gcd(b,a%b);
    else    return gcd(a,b%a);
}
int lcm(int a,int b){
    int p=a/gcd(a,b);
    return p*b;
}


/*************** Diophantine *********************/

int dioph(int a,int b,int &x,int &y){
    if(a==0){
        x=0;y=1;return b;     // X=(c/g)*x && Y=(c/g)*y
    }
    int x1,y1,g;
    g=dioph(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
}


/******************** Factorial***********************/

int fact[MAX];
void factorial(int m)
{
    fact[0]=1;fact[1]=1;
    for(int i=2;i<MAX;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=m;
    }
}


/******************MATRIX EXPO***********************/

vector<vector<int> > multiply(vector<vector<int> >&v1,vector<vector<int> >&v2){
    vector<vector<int> >mul={{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                mul[i][j]+=(v1[i][k]*v2[k][j]);
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            v1[i][j]=mul[i][j];
        }
    }
    return v1;
}
// Write this in main function
// vector<vector<int> >v1={{1,1},{1,0}};
// vector<vector<int> >mul=power(v1,n-2);
// cout << mul[0][0]*b+mul[0][1]*a;
vector<vector<int> > power(vector<vector<int> >&v1,int n){
    vector<vector<int> >v2={{1,-1},{1,0}};
    vector<vector<int> >res={{1,0},{0,1}};
    while(n){
        if(n&1) res=multiply(res,v1);
        v1=multiply(v1,v1);
        n/=2;
    }
    return res;
}

/*********************** Mpower***********************/

int power(int a,int b)
{
    int res=1;
    while(b){
        if(b&1) res=res*a;
        a=a*a; b>>=1;
    }
    return res;
}

int mpower(int a,int b,int m)
{
    if(b==0) return 1;
    if(b==1) return a%m;
    int res=1;
    a=a%m;
    while(b){
        if(b&1){
            res=(res*a)%m;
        }
        a=((a%m)*(a%m))%m;
        b>>=1;
    }
    return res;
}


/********************* Inverse Mod ********************/

int imod(int a,int m){
    if(__gcd(a,m)!=1)   return 0;
    return mpower(a,m-2,m);
}




/************************ NCR **********************/

int ncr(int n,int r,int m)
{
    factorial(m);
    if(r>n) return -1;
    int a=fact[n];
    int b=imod(fact[n-r],m);
    int c=imod(fact[r],m);
    a*=b; a%=m;
    a*=c; a%=m;
    return a;
}



/**************** LCM MOD **********************/

map<int,int> ma;
map<int,int>::iterator et;
int mlcm(vector<int>v,int n,int m)
{
    SPF();
    int i,num,factor,ans=1;
    for(i=0;i<n;i++){
        num=v[i];
        map<int,int> temp;
        map<int,int>::iterator it;
        while(num>1){
            temp[spf[num]]++;
            num/=spf[num];
        }
        for(it=temp.begin();it!=temp.end();++it){
            ma[it->first]=max(ma[it->first],it->second);
        }
    }
    for(et=ma.begin();et!=ma.end();++et){
        ans=(ans*mpower(et->first,et->second,m))%m;
    }
    return ans;
}
