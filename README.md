# My Template for CP

- [ALGORITHMS](#BIT)
  - [BIT](#BIT)
  - [Bit_Manipulation](#BitManipulation)
  - [Disjoint Set Union](#Disjoint_set_union)
  - [DFS](#DFS)
  - [Heap](#Visual)
    - [Visual](#Visual)
    - [Min Heap](#MinHeap)
    - [Max Heap](#MaxHeap)
  - [MO's_Algo](#Mos_Algo)
  - [NextPrev_GreaterSmaller](#NextPrev_GreaterSmaller)
  - [Nth Fibonacci](#NthFibonacci)
  - [Number Theory](#Power)
    - [Power](#Power)
    - [Sieve](#Sieve)
    - [Segmented Sieve](#SegmentedSieve)
    - [SPF](#SPF)
    - [ETF](#ETF)
    - [PHI](#PHI)
    - [GCD LCM](#GcdLcm)
    - [Diophantine](#Diophantine)
    - [Factorial](#Factorial)
    - [Matrix Expo](#MatrixExpo)
    - [Inverse Mod](#inverseMod)
    - [NCR](#NCR)

  - [Segment Tree](#Segment1)
    - [Point Update and Range Query](#Segment1)
    - [Range Update and Point Query](#Segment2)
  - [Sorting](#QuickSort)
    - [Quick Sort](#QuickSort)
    - [Merge Sort](#MergeSort)
    - [Heap Sort](#HeapSort)
  - [Sparse Table](#SparseTable)
  - [String Algo](#RabinKarp)
    - [Rabin Karp](#RabinKarp)
    - [PI Table](#PiTable)
  - [Trie](#Trie)
  - [Suffix Array](#Suffix_Array)

# BIT
``` C++
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
```

# BitManipulation
```C++
string binary(int num){
    string s="";
    if(num == 0)    s="0";
    int a;
    while(num){
        a = num%2; num/=2;
        s.push_back(a+'0');
    }
    int m = 32-s.length();
    for(int i=0;i<m;i++)    s.push_back('0');
    reverse(s.begin(),s.end());
    return s;
}
int decimal(string s){
    int num = 0;
    for(char ch:s){
        num<<=1;
        num|=(ch-'0');
    }
    return num;
}
int numberOfSetBit(int num){
    int cnt = 0;
    while(num>0){
        cnt++;
        num&=(num-1);
    }
    return cnt;
}
bool isPowerOfTwo(int num){
    if(num == 0)    return false;
    return (num&(num-1) == 0);
}
int rightMostSetBit(int num){
    if(num&1)   return 0;
    num = (num^(num&(num-1)));
    int pos = 0;
    while(num > 0){
        num>>=1;
        pos++;
    }
    return pos-1;
}
int getBitwiseAnd(int l,int r){
    if(l > r)   swap(l,r);
    if(l == r)  return l;
    int diff = r-l;
    int ans = 0;
    for(int i=0;i<32;i++){
        int a = (1ll<<i);
        int block1 = l/a;
        int block2 = r/a;
        if((diff>a) || (block1 != block2) || (block1%2==0)) continue;
        ans|=a;
    }
    return ans;
}
int getBitwiseXor(int l,int r){
    if(l > r)   swap(l,r);
    if(l == r)  return 0;
    int xl,xr;
    xr = ((r%4==0)?r:((r%4==1)?1:((r%4==2)?r+1:0)));
    if(l == 0){
        return xr;
    }
    l--;
    xl = ((l%4==0)?l:((l%4==1)?1:((l%4==2)?l+1:0)));
    return (xl^xr);
}
// some O(1) cost operation
/*
    calculate 2^n  -->   (1ll<<n);
    set ith bit of a number  -->    num|=(1ll<<i);
    flip ith bit of a number -->    num^=(1ll<<i);
    find ith bit of a number -->    b = num&(1ll<<i);
    unset ith bit of a number-->    n&=(~(1ll<<i));
    clear LSB set bit of a number -->   n&(n-1);
    find LSB set bit of a number  -->   n^(n&(n-1)),  n&(-n);
    check a number is power of 2 -->    n&(n-1)==0,  check for n=0 seperately !!!
*/
// other relations
/*
    a+b = (a|b) + (a&b);
    a+b = (a^b) + 2*(a&b);
    a|b = (a^b) + (a&b);
*/
```

# Disjoint_set_union
``` C++
class DSU{
    vector<int>par;
    vector<int>sz;
public:
    DSU(int n){
        par.resize(n+5);
        sz.resize(n+5,1);
        iota(par.begin(),par.end(),0);
    }
    int parent(int x){
        if(par[x]==x) return x;
        return par[x]=parent(par[x]);
    }
    bool is_same(int x,int y){
        return (parent(x)==parent(y));
    }
    void unionxy(int x,int y){
        int px=parent(x);
        int py=parent(y);
        if(px==py) return;
        if(sz[px]<sz[py])   swap(px,py);
        par[py]=px;
        sz[px]+=sz[py];
    }
};
```

# DFS
```C++
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
```

# Visual
```C++
/*
 ___________________________________
|                                   |
|	    Binary Heap             |
|___________________________________|
-> Binary heap is a complete binary tree
-> complete binary tree means it is binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
-> consider 0-based indexing we can find parent of a node and it's ;eft and right child as
	Left[i]=2*i+1;
	Right[i]=2*i+2;
	Parent[i]=(i-1)/2;
---> 		Min Heap
-> Complete binnary Tree
-> Every node has value smaller than its descendants
			    10
			   /   \
			  20    15
			 /  \   / \
		        30  40 18
		arr[]={10,20,15,30,40,18};
					
					    2
					   / \
					  4   8
					/  \  / \
				       6   5  9  10
				      / \
				    100 200
		arr[]={2,4,8,6,5,9,10,100,200};
*/

```

# MinHeap
```C++
// Everything is 1-based index
#include<bits/stdc++.h>
using namespace std;

const int capacity=100005;
class minHeap{
	private:
		int index;
		int arr[capacity];
		int left(int id){
			return 2*id;
		}
		int right(int id){
			return 2*id+1;
		}
		int parent(int id){
			return id/2;
		}
		int getmin_(){
			if(index==0)	return INT_MAX;
			return arr[1];
		}
		void insert_(int x){
			if(index+1==capacity)	return;
			index++;
			arr[index]=x;
			int cur=index,par;
			while(cur>1){
				par=parent(cur);
				if(arr[par]>arr[cur]){
					swap(arr[par],arr[cur]);
					cur=par;
				}
				else{
					break;
				}
			}
		}
		int search_(int x){
			for(int i=1;i<=index;i++){
				if(arr[i]==x)	return i;
			}
			return 0;
		}
		void min_heapify(int id){
			int l=left(id),r=right(id),cur=id;
			if(l<index && arr[l]<arr[cur])	cur=l;
			if(r<index && arr[r]<arr[cur])	cur=r;
			if(cur!=id){
				swap(arr[cur],arr[id]);
				min_heapify(cur);
			}
		}
		void deletex(int x){
			int id=search_(x);
			if(id==0)	return;
			arr[id]=arr[index];
			index--;
			min_heapify(id);
		}
	public:
		minHeap(){ index=0; }
		int getmin(){ return getmin_(); }
		void insert(int x){ insert_(x); }
		int search(int x){ return search_(x); }
		void remove(int x){ deletex(x); }
		int size(){ return index; }
		int top(){ return getmin(); }
		void pop(){ deletex(getmin()); }

		void print(){
			cout << "arr[]={";
			for(int i=1;i<=index;i++){
				cout << arr[i] << ",";
			}
			cout << "}" << endl;
		}
};
```

# MaxHeap
```C++
class maxHeap{
	private:
		int index;
		int arr[capacity];
		int left(int id){
			return 2*id;
		}
		int right(int id){
			return 2*id+1;
		}
		int parent(int id){
			return id/2;
		}
		int getmax_(){
			if(index==0)	return INT_MIN;
			return arr[1];
		}
		int search_(int x){
			for(int i=1;i<=index;i++){
				if(arr[i]==x)	return i;
			}
			return 0;
		}
		void insert_(int x){
			if(index+1==capacity)	return;
			index++;
			arr[index]=x;
			int cur=index,par;
			while(cur>1){
				par=parent(cur);
				if(arr[par]<arr[cur]){
					swap(arr[par],arr[cur]);
					cur=par;
				}
				else{
					break;
				}
			}
		}
		void max_heapify(int id){
			int l=left(id),r=right(id),cur=id;
			if(l<index && arr[l]>arr[cur])	cur=l;
			if(r<index && arr[r]>arr[cur])	cur=r;
			if(cur!=id){
				swap(arr[cur],arr[id]);
				max_heapify(cur);
			}
		}
		void deletex(int x){
			int id=search_(x);
			if(id==0)	return;
			arr[id]=arr[index];
			index--;
			max_heapify(id);
		}
	public:
		maxHeap(){ index=0; }
		int getmax(){ return getmax_(); }
		void insert(int x){ insert_(x); }
		int search(int x){ return search_(x); }
		void remove(int x){ deletex(x); }
		int size(){ return index; }
		int top(){ return getmax(); }
		void pop(){ deletex(getmax()); }

		void print(){
			cout << "arr[]={";
			for(int i=1;i<=index;i++){
				cout << arr[i] << ",";
			}
			cout << "}" << endl;
		}
};

int main(){
	maxHeap h;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		h.insert(x);
		cout << "Size=" << h.size() << endl;
		cout << "Min value=" << h.getmax() << endl;
		h.print();
	}

	return 0;
}
```

# Mo's_Algo
```C++
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
```

# NextPrev_GreaterSmaller
```C++
struct NextPrev{
	// next and prev vectors show n and -1 respectively in case when
	// required element doesn't exists in vector.
	vector<int> nextgreater, prevgreater, nextsmaller, prevsmaller, a;
	int n;
	NextPrev(vector<int> &arr){
		a = vector<int>(arr.begin(), arr.end());
		n = a.size();
	}
	void calcNextGreater(){
		nextgreater = vector<int>(n, n);
		stack<int> st;
		for(int i=n-1;i>=0;i--){
		    while(!st.empty() && a[st.top()]<=a[i])   st.pop();
		    nextgreater[i]=(st.empty()?n:st.top());
		    st.push(i);
		}
		return;
	}
	void calcNextSmaller(){
		nextsmaller = vector<int>(n, n);
		stack<int> st;
		for(int i = 0 ; i < n ; i++){
			while(!st.empty() && a[st.top()] > a[i]){
				nextsmaller[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		return;
	}
	void calcPrevSmaller(){
		prevsmaller = vector<int> (n, -1);
		stack<int> st;
		for(int i = n - 1 ; i >= 0 ; i--){
			while(!st.empty() && a[i] < a[st.top()]){
				prevsmaller[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		return;
	}
	void calcPrevGreater(){
		prevgreater = vector<int>(n, -1);
		stack<int> st;
		for(int i = n - 1 ; i >= 0 ; i--){
			while(!st.empty() && a[i] > a[st.top()]){
				prevgreater[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		return;
	}
};
```

# NthFibonacci

```C++
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
int getNthFibonacci(int a,int b,int n){
    if(n==0)    return a;
    if(n==1)    return b;
    vector<vector<int> >v1={{1,1},{1,0}};
    vector<vector<int> >mul=power(v1,n-1);
    int x=mul[0][0]*b+mul[0][1]*a;
    return x;
}

int32_t main(){
    
    int a,b,n;
    cin >> a >> b >> n;
    vector<vector<int> >v1={{1,1},{1,0}};
    vector<vector<int> >mul=power(v1,n-2);
    cout << getNthFibonacci(a,b,n) << endl;     // Fibonacci position starts from 0
    
    return 0;
}
```


# Power
```C++
int power(int a,int b)
{
    int res=1;
    while(b){
        if(b&1) res=res*a;
        a=a*a; b>>=1;
    }
    return res;
}

int power(int a,int b,int m)
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
```

# Sieve
```C++
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
```

# SegmentedSieve
```C++
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
```

# SPF
```C++
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
```

# ETF
```C++
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
```

# PHI
```C++
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
```

# GcdLcm
```C++
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
```

# Diophantine
```C++
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
```

# Factorial
```C++
int fact[MAX];
void factorial(int m)
{
    fact[0]=1;fact[1]=1;
    for(int i=2;i<MAX;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=m;
    }
}
```

# MatrixExpo
```C++
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
```

# inverseMod
```C++
int power(int a,int b,int m)
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
int imod(int a,int m){
    if(__gcd(a,m)!=1)   return 0;
    return power(a,m-2,m);
}
```

# NCR
```C++
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
```

# Segment1

```C++
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

```

# Segment2
```C++
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
```

# QuickSort
```C++
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
```

# MergeSort
```C++
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
```

# HeapSort
```C++
void max_heapify(vector<int>&v,int n,int id){
    int maxi=id;
    int l=2*id+1;
    int r=2*id+2;
    if(l<n && v[l]>v[maxi]) maxi=l;     // find index of maximum element amont current node, left and right child
    if(r<n && v[r]>v[maxi]) maxi=r;
    if(maxi!=id){                       // If maximum index is not the current index then do swap and heapify for max-index
        swap(v[id],v[maxi]);
        max_heapify(v,n,maxi);
    }
}
//  build max-heap
void build_heap(vector<int>&v){
    const int n=v.size();
    for(int i=n/2-1;i>=0;i--){
        max_heapify(v,n,i);
    }
}
void Hsort(vector<int>&v){
    build_heap(v);                  // 1st build the array a proper max heap
    const int n=v.size();
    for(int i=n-1;i>0;i--){
        swap(v[0],v[i]);            // every time swap the max value with last value
        max_heapify(v,i,0);         // Again apply heapify for that index in the root node till i-th index
    }
}
```

# SparseTable
```C++
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
```

# RabinKarp
```C++
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
```

# PiTable
```C++
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
```

# Trie
```C++
const int K=26;
class Node{
public:
    int eow=0;
    Node* child[K];
    Node(){
        eow=0;
        for(int i=0;i<K;i++){
            child[i]=NULL;
        }
    }
};
class Trie{
    Node* root=new Node();
    void insert_string(string &s){
        const int n=s.length();
        Node* cur=root;
        for(int i=0;i<n;i++){
            int id=s[i]-'a';
            if(!cur->child[id]){
                cur->child[id]=new Node();
            }
            cur=cur->child[id];
        }
        (cur->eow)++;
    }
    bool search(string &s){
        const int n=s.length();
        Node* cur=root;
        for(int i=0;i<n;i++){
            int id=s[i]-'a';
            if(!cur->child[id]) return false;
            cur=cur->child[id];
        }
        if(cur!=NULL && cur->eow!=0)    return true;
        return false;
    }
    bool startsWith(string &s) {
        const int n=s.length();
        Node* cur=root;
        for(int i=0;i<n;i++){
            int id=s[i]-'a';
            if(!cur->child[id]) return false;
            cur=cur->child[id];
        }
        if(cur!=NULL)    return true;
        return false;
    }
    Node* deleteword(Node* ptr,string &s,int id){
        if(ptr==NULL)   return NULL;
        int n=s.length();
        if(id==n){
            if(ptr->eow){
                ptr->eow=false;
            }
            bool ok=true;
            for(int i=0;i<26;i++){
                if(ptr->child[i])   ok=false;
            }
            if(ok){
                delete(ptr);
                ptr=NULL;
            }
            return ptr;
        }
        int sid=s[id]-'a';
        ptr->child[sid]=deleteword(ptr->child[sid],s,id+1);
        bool ok1=true;
        for(int i=0;i<26;i++){
            if(ptr->child[i])  ok1=false;
        }
        if(ok1 && (ptr->eow == false)){
            delete(ptr);
            ptr=NULL;
        }
        return ptr;
    }
public:
    void insert(string &s){
        insert_string(s);
    }
    bool is_present(string &s){
        return search(s);
    }
    bool is_prefix(string &s){
        return startsWith(s);
    }
    void remove(string &s){
        if(!is_present(s)){
            return;
        }
        root=deleteword(root,s,0);
    }
};
```

# Suffix_Array
``` C++
void countSort(vector<int> &p,vector<int> &c)
{
    int n = p.size();
    vector<int> cnt(n);
    for(auto x:c)   cnt[x]++;
    vector<int> p_new(n),pos(n);
 
    pos[0]=0;
    for(int i=1;i<n;i++)
        pos[i] = pos[i-1] + cnt[i-1];
 
    for(auto x:p) {
        p_new[pos[c[x]]] = x;
        pos[c[x]]++;
    }
    p = p_new;
}

vector<int> getSuffixPosition(string &s)
{
    s += "$";
    int n=s.length();
    vector<int>pos(n),c(n);
    vector<pair<char,int > > a(n);
 
    for(int i=0;i<n;i++){
        a[i] = {s[i], i};
    }
    sort(a.begin(),a.end());
 
    for(int i=0;i<n;i++){
        pos[i] = a[i].second;
    }
    c[pos[0]] = 0;
    for(int i=1;i<n;i++){
        if(a[i].first == a[i-1].first){
            c[pos[i]] = c[pos[i-1]];
        }
        else{
            c[pos[i]] = c[pos[i-1]]+1;
        }
    }
 
    int k = 0;
    vector<int> c_new(n);
    while((1ll<<k) < n)
    {
        for(int i=0;i<n;i++){
            pos[i] = (pos[i] - (1ll<<k) + n)%n;
        }
 
        countSort(pos,c);
 
        c_new[pos[0]] = 0;
        for(int i=1;i<n;i++){
            pair<int,int> prev = {c[pos[i-1]], c[(pos[i-1]+(1ll<<k))%n]};
            pair<int,int> now = {c[pos[i]], c[(pos[i]+(1ll<<k))%n]};
            if(prev == now){
                c_new[pos[i]] = c_new[pos[i-1]];
            }
            else{
                c_new[pos[i]] = c_new[pos[i-1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    return pos;
}

vector<int> getLCP(string &s, vector<int>&p){
    int n = s.length();

    vector<int>c(n,0);
    for(int i=0;i<n;i++)    c[p[i]] = i;
    
    vector<int>lcp(n-1,0);
    int k = 0;
    
    for(int i=0;i<n-1;i++){
        int x = c[i]-1;
        int j = p[x];
        while(s[i+k] == s[j+k])    k++;
        lcp[x] = k;
        k = max(k-1, 0);
    }
    
    return lcp;
}
```
