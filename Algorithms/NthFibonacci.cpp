vector<vector<int> > multiply(vector<vector<int> >&v1,vector<vector<int> >&v2){
    vector<vector<int> >mul={{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                mul[i][j]+=(v1[i][k]*v2[k][j]);
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            v1[i][j]=mul[i][j];
        }
    }
    return v1;
}
vector<vector<int> > power(vector<vector<int> >&v1,int n){
    vector<vector<int> >v2={{1,-1},{1,0}};
    vector<vector<int> >res={{1,0},{0,1}};
    while(n){
        if(n&1) res=multiply(res,v1);
        v1=multiply(v1,v1);
        n/=2;
    }
    return res;
}
int getNthFibonacci(int a,int b,int n){
    if(n==0)    return a;
    if(n==1)    return b;
    vector<vector<int> >v1={{1,1},{1,0}};
    vector<vector<int> >mul=power(v1,n-1);
    int x=mul[0][0]*b+mul[0][1]*a;
    return x;
}

int32_t main(){
    
    int a,b,n;
    cin >> a >> b >> n;
    vector<vector<int> >v1={{1,1},{1,0}};
    vector<vector<int> >mul=power(v1,n-2);
    cout << getNthFibonacci(a,b,n) << endl;     // Fibonacci position starts from 0
    
    return 0;
}
