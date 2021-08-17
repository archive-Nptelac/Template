# My Template for CP

- [ALGORITHMS](#ALGORITHMS)
- [DATA STRUCTURES](#DATASTRUCTURES)
- [DESIGN](#DESIGN)
- [CORE](#CORE)

# ALGORITHMS

- [DSU](#DSU)

# DSU
``` C++
class DSU{
    vector<int>par;
    vector<int>sz;
public:
    DSU(int n){
        par.resize(n+5);
        sz.resize(n+5,1);
        iota(par.begin(),par.end(),0);
    }
    int parent(int x){
        if(par[x]==x) return x;
        return par[x]=parent(par[x]);
    }
    bool is_same(int x,int y){
        return (parent(x)==parent(y));
    }
    void unionxy(int x,int y){
        int px=parent(x);
        int py=parent(y);
        if(px==py) return;
        if(sz[px]<sz[py])   swap(px,py);
        par[py]=px;
        sz[px]+=sz[py];
    }
};
```
