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
