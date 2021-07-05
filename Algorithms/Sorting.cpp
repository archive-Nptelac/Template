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


/*************************** Heap Sort *****************************/

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

/*************************************************************/
