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
