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


