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

