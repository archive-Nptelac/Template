class Queue{
    private:
        int cap=MAX;
        int arr[MAX];
        int f=(-1),r=(-1);
    public:
        bool empty(){
            return (f==(-1));
        }
        bool full(){
            return ((r+1)%cap==f);
        }
        int size(){
            return ((cap-f+r+1)%cap);
        }
        void pop(){
            if(f==(-1)) return;
            if(f==r){
                f=(-1);
                r=(-1);
            }
            else{
                f=(f+1)%cap;
            }
        }
        void push(int x){
            if((r+1)%cap==f) return;
            r=(r+1)%cap;
            arr[r]=x;
            if(f==(-1)) f=r;
        }
        int front(){
            if(f==(-1)) return -1;
            int num=arr[f];
            return num;
        }
        int rear(){
            if(f==(-1)) return -1;
            int num=arr[r];
            return num;
        }
        void rpush(int x){
            if((r+1)%cap==f) return;
            if(f==(-1)) f=0;
            else f=(f-1+cap)%cap;
            arr[f]=x;
            if(r==(-1)) r=f;
        }
        void rpop(){
            if(r==(-1)||f==(-1)) return;
            if(f==r){
                f=(-1); r=(-1);
            }
            else{
                r=(r-1+cap)%cap;
            }
        }
};
