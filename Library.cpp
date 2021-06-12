#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MAX 100005
#define INF 1e18
#define pb push_back
int max(int a,int b){if(a>b) return a;return b;}
int min(int a,int b){if(a>b) return b;return a;}
// Binary to decimal <=> Decimal to Binary
    
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

/***************** String Algorithm ******************/

/*************** Rabin Karp Algorithm ****************/

vector<int> rabin_karp(string const& s, string const& text) {       // find occurance of s in the given text
    const int p = 31;                                               // Time Complexity:- O(|S|+|text|);
    const int m = 1e9 + 9;
    int S = s.size(), T = text.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

/****************** KMP   Pi-array ********************/

vector<int> pi_table(string s) {
    int n = (int)s.length();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}


/******************* MO's Algorithm *********************/

const int root=555;
int distinct;                                                   // Total distinct value in the current range [L,R];
int freq[MAX];                                                  // Frequency of each element
int arr[MAX];                                                   // Input array use 1-based indexing
struct Query{
    int low,high,query_num,block_num;

    bool operator < (Query &q){
        if(block_num==q.block_num)  return high<q.high;
        return block_num<q.block_num;
    }

};
void add(int& x){
    if(freq[x]==0)  distinct++;
    freq[x]++;
}
void remove(int& x){
    freq[x]--;
    if(freq[x]==0)  distinct--;
}
void changelr(int& low,int& high,Query &q){
    while(low>q.low){
        low--;
        add(arr[low]);
    }
    while(low<q.low){
        remove(arr[low]);
        low++;
    }
    while(high<q.high){
        high++;
        add(arr[high]);
    }
    while(high>q.high){
        remove(arr[high]);
        high--;
    }
}
void solve_query(vector<Query>&v){
    sort(v.begin(),v.end());
    int m=v.size();
    vector<int>res(m);
    memset(freq,0,sizeof(freq));
    int cl,cr;
    cl=v[0].low;
    cr=v[0].low;
    freq[arr[cl]]++;
    distinct=1;
    for(Query& q:v){
        changelr(cl,cr,q);
        res[q.query_num]=distinct;
    }
    
    for(int i=0;i<m;i++){
        printf("%lld\n",res[i]);
    }
}

/************************BIT*****************************/

class BIT{
    vector<int>bit;                         // 1-based indexing
    int n;
public:
    BIT(int sz){
        n=sz;
        bit.resize(n+1,0);
    }
    BIT(vector<int>&v){                     // v is 0-based indexing
        n=v.size();
        bit.assign(n+1,0);                  // bit is 1-based indexing
        for(int i=0;i<n;i++){
            update(i+1,v[i]);               // 1-based indexing
        }
    }
    void update(int k,int val){
        while(k<=n){
            bit[k]+=val;
            k+=(k&(-k));
        }
    }
    int getsum(int k){                      // returns sum[1,k];
        int s=0;
        while(k>0){
            s+=bit[k];
            k-=(k&(-k));
        }
        return s;
    }
    int getsum(int l,int r){                // returns sum[l,r];
        return getsum(r)-getsum(l-1);
    }
};


/****************** Sparse Table ********************/

int st[MAX][25];
int change_st(int a,int b){                         // Change is accordingly
    return min(a,b);
}
void build(vector<int>&v){                          // vector v is 0-based indexing
    int n=v.size();
    for(int i=0;i<n;i++)    st[i][0]=v[i];
    for(int j=1;(1ll<<j)<=n;j++){
        for(int i=0;i+(1ll<<j)-1<n;i++){
            st[i][j]=change_st(st[i][j-1],st[i+(1ll<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r){                             // get result in the range [L,R]
    int total=r-l+1;
    int k=log2(total);
    int ans=st[l][k];
    int rem=total-(1ll<<k);
    ans=change_st(ans,st[l+rem][k]);
    return ans;
}


/**************** Segment tree ************************/

/*********** Point update and range query **************/

class segment{
    int size;
    vector<int>T;
    private:
        int changeT(int f,int s){                           // change it accordingly
            return f+s;
        }
        
        void build(vector<int>&v,int pos,int left,int right){
            int mid=left+(right-left)/2;
            if(left==right){
                if(left<v.size()){
                    T[pos]=v[left];
                }
                return;
            }
            
            build(v,2*pos+1,left,mid);
            build(v,2*pos+2,mid+1,right);
            
            T[pos]=changeT(T[2*pos+1],T[2*pos+2]);
            return;
        }
        
        int get(int low,int high,int pos,int left,int right){
            int mid=left+(right-left)/2;
            if(left>high)   return 0;
            if(right<low)   return 0;
            if(low<=left && high>=right)    return T[pos];
            
            int x1=get(low,high,2*pos+1,left,mid);
            int x2=get(low,high,2*pos+2,mid+1,right);
            
            return changeT(x1,x2);
        }
        
        void update(int ind,int val,int pos,int left,int right){
            if(left==right){
                T[pos]=val;
                return;
            }
            
            int mid=left+(right-left)/2;
            if(ind<=mid){
                update(ind,val,2*pos+1,left,mid);
            }
            else{
                update(ind,val,2*pos+2,mid+1,right);
            }
            
            T[pos]=changeT(T[2*pos+1],T[2*pos+2]);
        }
        
    public:
        segment(vector<int>&v){
            int n=v.size();
            size=1;
            while(size<n)   size*=2;
            T.assign(2*size,0ll);
            build(v,0,0,size-1);
            // cout << size << endl;
        }
        int getsum(int l,int r){                        // gives sum in close interval [l,r];
            return get(l,r,0,0,size-1);                 // l and r are 0-based index;
        }
        void setval(int pos,int val){                   // pos is 0-based index
            update(pos,val,0,0,size-1);
        }
};                                                      // Intialize variable as segment tree(v);

/************ range update and point query ************/

class segment2{
    int size;
    vector<int>T;
    private:
        int changeT(int f,int s){
            return f+s;
        }
        
        // int changeT(int f,int s){                    // part of lazy propagation
        //     if(s==INF)  return f;
        //     return s;
        // }
        
        void propagate(int pos,int left,int right){  // part of lazy propagation
            if(left==right) return;
            T[2*pos+1]=changeT(T[2*pos+1],T[pos]);
            T[2*pos+2]=changeT(T[2*pos+2],T[pos]);
            T[pos]=INF;
        }
        
        void update(int l,int r,int val,int pos,int left,int right){
            // propagate(pos,left,right);                   // Part of lazy propagation
            if(left>r||right<l) return;
            if(left>=l && right<=r){
                T[pos]=changeT(T[pos],val);
                return;
            }
            int mid=left+(right-left)/2;
            update(l,r,val,2*pos+1,left,mid);
            update(l,r,val,2*pos+2,mid+1,right);
            return;
        }
        
        int get(int id){
            // propagate(pos,left,right);                  // Part of lazy propagation
            int ans=0;
            while(true){
                if(id==0){
                    ans=changeT(ans,T[id]);
                    break;
                }
                ans=changeT(ans,T[id]);
                id--;id/=2;
            }
            return ans;
        }
        
    public:
        segment2(int n){
            size=1;
            while(size<n)   size*=2;
            T.assign(2*size,0ll);
            // cout << size << endl;
        }
        int getval(int id){                     // id should be 0-based index
            return get(id+size-1);
        }
        void addval(int l,int r,int val){       // add val to A[l,r] (including);
            update(l,r,val,0,0,size-1);
        }
};


/********************** Stack ************************/

class Stack{
    private:
        int s=MAX;
        int a[MAX];
        int t=(-1);
    public:
        int top(){
            return (t==(-1)?-1:a[t]);
        }
        void pop(){
            t--; t=max(t,-1);
        }
        void push(int x){
            if(t==s-1) return;
            t++; a[t]=x;
        }
        int size(){
            return t+1;
        }
        bool empty(){
            return (t==(-1));
        }
        bool full(){
            return (t==s-1);
        }
};

/********************** Queue ********************/

class Queue{
    private:
        int cap=MAX;
        int arr[MAX];
        int f=(-1),r=(-1);
    public:
        bool empty(){
            return (f==(-1));
        }
        bool full(){
            return ((r+1)%cap==f);
        }
        int size(){
            return ((cap-f+r+1)%cap);
        }
        void pop(){
            if(f==(-1)) return;
            if(f==r){
                f=(-1);
                r=(-1);
            }
            else{
                f=(f+1)%cap;
            }
        }
        void push(int x){
            if((r+1)%cap==f) return;
            r=(r+1)%cap;
            arr[r]=x;
            if(f==(-1)) f=r;
        }
        int front(){
            if(f==(-1)) return -1;
            int num=arr[f];
            return num;
        }
        int rear(){
            if(f==(-1)) return -1;
            int num=arr[r];
            return num;
        }
        void rpush(int x){
            if((r+1)%cap==f) return;
            if(f==(-1)) f=0;
            else f=(f-1+cap)%cap;
            arr[f]=x;
            if(r==(-1)) r=f;
        }
        void rpop(){
            if(r==(-1)||f==(-1)) return;
            if(f==r){
                f=(-1); r=(-1);
            }
            else{
                r=(r-1+cap)%cap;
            }
        }
};

/********************* Min Heap **********************/

class Minheap{
    private:
        int index=0;
        int arr[MAX+1];
    public:
        Minheap(){
            index=0;
        }
        int getmin(){
            if(index==0) return -1;
            return arr[1];
        }
        void insert(int x){
            if(index==MAX) return;
            index++;
            arr[index]=x;
            int p=index;
            int pr;
            while(p>1){
                pr=p/2;
                if(arr[pr]>arr[p]){
                    swap(arr[pr],arr[p]);
                    p=pr;
                }
                else{
                    break;
                }
            }
        }
        int search(int x){
            for(int i=1;i<=index;i++){
                if(arr[i]==x) return i;
            }
            return -1;
        }
        void min_heapify(int i){
            int low,high,mid;
            low=2*i; high=low+1; mid=i;
            if(low<index && arr[low]<arr[mid]){
                mid=low;
            }
            if(high<index && arr[high]<arr[mid]){
                mid=high;
            }
            if(mid!=i){
                swap(arr[mid],arr[i]);
                min_heapify(mid);
            }
        }
        void deletex(int x){
            int i=search(x);
            arr[i]=arr[index];
            index--;
            min_heapify(i);
        }
};


/********************** DFS ************************/

bool vis[MAX];
int par[MAX];
vector<vector<int> >adj(MAX);
void dfs(int x)
{
    vis[x]=true;
    cout << x << " ";
    for(int j=0;j<adj[x].size();j++){
        int p=adj[x][j];
        if(!vis[p]){
            par[p]=x;
            dfs(p);
        }
    }
}


/******************* DSU **************************/

int par[MAX];
int sz[MAX];
void init(){
    for(int i=0;i<MAX;i++){
        par[i]=i;
        sz[i]=1;
    }
}
int parent(int x){
    if(par[x]==x) return x;
    par[x]=parent(par[x]);
    return par[x];
}
void unionxy(int x,int y){
    int px=parent(x);
    int py=parent(y);
    if(px==py) return;
    par[py]=px;
    sz[px]+=sz[py];
}


/*********************** Quick sort ******************/

int Partition(vector<int>&v,int low,int high){
    int i,j,pivot,temp;
    pivot=v[high];
    i=low-1;
    for(j=low;j<=high-1;j++){
        if(v[j]<=pivot){
            i++;
            temp=v[j];
            v[j]=v[i];
            v[i]=temp;
        }
    }
    temp=v[i+1];
    v[i+1]=v[high];
    v[high]=temp;
    return i+1;
}
void Qsort(vector<int>&v,int low,int high){
    int p;
    if(low<high){
        p=Partition(v,low,high);
        Qsort(v,low,p-1);
        Qsort(v,p+1,high);
    }
}

/****************** Merge Sort *****************/

void Merge(vector<int>&v,int low,int mid,int high){
    int i,j,k,n1,n2;
    n1=mid-low+1;
    n2=high-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++) L[i]=v[low+i];
    for(i=0;i<n2;i++) R[i]=v[mid+1+i];
    i=0;j=0;k=low;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            v[k]=L[i]; i++;
        }
        else{
            v[k]=R[j]; j++;
        }
        k++;
    }
    while(i<n1){
        v[k]=L[i];i++;k++;
    }
    while(j<n2){
        v[k]=R[j];k++;j++;
    }
}
void Msort(vector<int>&v,int low,int high)
{
    int mid;
    if(low<high){
        mid=low+(high-low)/2;
        Msort(v,low,mid);
        Msort(v,mid+1,high);
        Merge(v,low,mid,high);
    }
}



/************************ BST ***********************/

struct bst{
    int data;
    struct bst *left,*right;
};
struct bst* newd(){
    struct bst *ptr=(struct bst*) malloc(sizeof(struct bst));
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
struct bst* insert(struct bst *root,struct bst *temp){
    if(root==NULL){
        root=temp;return root;
    }
    if(temp->data>root->data){
        root->right=insert(root->right,temp);
    }
    else{
        root->left=insert(root->left,temp);
    }
    return root;
}
void postorder(struct bst *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(struct bst *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct bst *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelorder(struct bst *root){
    if(root==NULL) return;
    queue<struct bst*>qe;
    qe.push(root);
    struct bst *temp;
    while(!qe.empty()){
        temp=qe.front();qe.pop();
        cout<<temp->data<<" ";
        if(temp->left) qe.push(root->left);
        if(temp->right) qe.push(root->right);
    }
}
void mirror(struct bst *root){
    if(root==NULL) return;
    mirror(root->left);
    mirror(root->right);
    struct bst *ptr=root->left;
    root->left=root->right;
    root->right=ptr;
}


int32_t main()
{
    
    return 0;
}
