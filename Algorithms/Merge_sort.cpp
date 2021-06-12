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
