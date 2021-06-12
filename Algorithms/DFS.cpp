bool vis[MAX];
int par[MAX];
vector<vector<int> >adj(MAX);
void dfs(int x)
{
    vis[x]=true;
    cout << x << " ";
    for(int j=0;j<adj[x].size();j++){
        int p=adj[x][j];
        if(!vis[p]){
            par[p]=x;
            dfs(p);
        }
    }
}
