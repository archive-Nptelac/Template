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
