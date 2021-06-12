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
