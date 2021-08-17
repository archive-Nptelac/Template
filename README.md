# My Template for CP

- [ALGORITHMS](#ALGORITHMS)
  - [BIT](#BIT)
  - [Binary_Decimal](#Binary_Decimal)
  - [Disjoint Set Union](#Disjoint_set_union)
  - [DFS](#DFS)
  - [Heap](#Heap)
  - [MO's_Algo](#Mo's_Algo)
  - [NextPrev_GreaterSmaller](#NextPrev_GreaterSmaller)
  - [Nth Fibonacci](#NthFibonacci)
  - [Number Theory](#NumberTheory)
  - [Segment Tree](#SegmentTree)
  - [Sorting](#Sorting)
  - [Sparse Table](#Sparsetable)
  - [String Algo (KMP, Pi Table)](#StringAlgo)
  - [Trie](#Trie)
- [DATA STRUCTURES](#DATASTRUCTURES)
- [DESIGN](#DESIGN)
- [CORE](#CORE)

# BIT
``` C++
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
```

# Binary_Decimal
```C++
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

# Disjoint set union
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

# Heap
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

# SegmentTree

```C++

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
```

