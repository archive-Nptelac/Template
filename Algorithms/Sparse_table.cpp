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
