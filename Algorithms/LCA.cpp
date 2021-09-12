int getLca(int a,int b){
    if(level[a]>level[b]){
        swap(a,b);
    }
    int d = level[b] - level[a];
    while(d>0){
        b = par[b];
        d--;
    }
    if(a == b)  return a;
    while(par[a] != par[b]){
        a = par[a];
        b = par[b];
    }
    return par[a];
    // Time Complexity: O(n)
    // Space Complexity: O(n)
}
// using binary lifting + sparse table

void init(){
    bfs(1);  // to calculate level of each node taking 1 as root node as well as LCA[i][0];
    for(int j=1; j<=maxN; j++){
        for(int i=1; i<=N; i++){
            int par = LCA[i][j-1];
            if(par != -1){
                LCA[i][j] = LCA[par][j-1];
            }
        }
    }
}
int getLca(int a,int b){
    if(level[a]>level[b]){
        swap(a,b);
    }
    int d = level[b] - level[a];
    while(d>0){
        int i = log2(d);
        b = LCA[b][i];
        d -= (1<<i);
    }
    if(a == b)  return a;
    for(int i=maxN;i>=0;i--){
        if(LCA[a][i]!=-1 && (LCA[a][i] != LCA[b][i])){
            a = LCA[a][i]; b = LCA[b][i];
        }
    }
    return LCA[a][0];
    // time complexity: O(nlogn + logn) nlogn building sparse table + logn per query
    // space complexity: O(nlogn)
}

// distance between two nodes in a tree (not valid for graph)
// dist(a,b) = level[a] + level[b] - 2*level[LCA(a,b)];
