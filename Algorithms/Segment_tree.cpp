
/**************** Segment tree ************************/

/*********** Point update and range query **************/

class segment{
    int size;
    vector<int>T;
    private:
        int changeT(int f,int s){                           // change it accordingly
            return f+s;
        }
        
        void build(vector<int>&v,int pos,int left,int right){
            int mid=left+(right-left)/2;
            if(left==right){
                if(left<v.size()){
                    T[pos]=v[left];
                }
                return;
            }
            
            build(v,2*pos+1,left,mid);
            build(v,2*pos+2,mid+1,right);
            
            T[pos]=changeT(T[2*pos+1],T[2*pos+2]);
            return;
        }
        
        int get(int low,int high,int pos,int left,int right){
            int mid=left+(right-left)/2;
            if(left>high)   return 0;
            if(right<low)   return 0;
            if(low<=left && high>=right)    return T[pos];
            
            int x1=get(low,high,2*pos+1,left,mid);
            int x2=get(low,high,2*pos+2,mid+1,right);
            
            return changeT(x1,x2);
        }
        
        void update(int ind,int val,int pos,int left,int right){
            if(left==right){
                T[pos]=val;
                return;
            }
            
            int mid=left+(right-left)/2;
            if(ind<=mid){
                update(ind,val,2*pos+1,left,mid);
            }
            else{
                update(ind,val,2*pos+2,mid+1,right);
            }
            
            T[pos]=changeT(T[2*pos+1],T[2*pos+2]);
        }
        
    public:
        segment(vector<int>&v){
            int n=v.size();
            size=1;
            while(size<n)   size*=2;
            T.assign(2*size,0ll);
            build(v,0,0,size-1);
            // cout << size << endl;
        }
        int getsum(int l,int r){                        // gives sum in close interval [l,r];
            return get(l,r,0,0,size-1);                 // l and r are 0-based index;
        }
        void setval(int pos,int val){                   // pos is 0-based index
            update(pos,val,0,0,size-1);
        }
};                                                      // Intialize variable as segment tree(v);



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
