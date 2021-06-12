int par[MAX];
int sz[MAX];
void init(){
    for(int i=0;i<MAX;i++){
        par[i]=i;
        sz[i]=1;
    }
}
int parent(int x){
    if(par[x]==x) return x;
    par[x]=parent(par[x]);
    return par[x];
}
void unionxy(int x,int y){
    int px=parent(x);
    int py=parent(y);
    if(px==py) return;
    par[py]=px;
    sz[px]+=sz[py];
}
