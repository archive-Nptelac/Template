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
