class Stack{
    private:
        int s=MAX;
        int a[MAX];
        int t=(-1);
    public:
        int top(){
            return (t==(-1)?-1:a[t]);
        }
        void pop(){
            t--; t=max(t,-1);
        }
        void push(int x){
            if(t==s-1) return;
            t++; a[t]=x;
        }
        int size(){
            return t+1;
        }
        bool empty(){
            return (t==(-1));
        }
        bool full(){
            return (t==s-1);
        }
};
