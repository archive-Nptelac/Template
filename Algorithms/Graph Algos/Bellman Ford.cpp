#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int INF = 1e18;

void solve(int the)
{
    int n,m,a,b,c;
    cin >> n >> m;
    vector<pair<int,pair<int,int> > >v;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    // apply bellman ford algorithm to detect cycle with negative weight;

    vector<int>dist(n+1,INF); // initial distance of all nodes;
    dist[1] = 0;
    vector<int>par(n+1,-1);
    int last_updated;
    // we need only n-1 operation but we will do n operation and if in Nth operation any of the node get relaxed then there must be a cycle
    for(int i=0;i<n;i++){
        last_updated = -1;
        for(int j=0;j<m;j++){
            a = v[j].second.first;
            b = v[j].second.second;
            c = v[j].first;
            if(dist[b] > dist[a] + c){
                dist[b] = max(dist[a] + c, -INF);
                par[b] = a;
                last_updated = b;
            }
        }
    }
    
    // If any node get relaxed in Nth operation then there will be a cycle.
    if(last_updated == -1){
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
  
    // now we know that there is a cycle but the last updated node may be a part of cycle or may not be to find this just do nth parent of this last updated node
  
    int ultimate = last_updated;
    for(int i=0;i<n;i++){
        ultimate = par[ultimate];
    }

    vector<int>path;
    for(int cur = ultimate; ; cur = par[cur]){
        path.push_back(cur);
        if(cur == ultimate && path.size() > 1){
            break;
        }
    }

    reverse(path.begin(),path.end());
    for(int x:path) cout << x << " "; cout << endl;


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    io_code();
    int t=1,c=1;
    // cin >> t;
    while(t--){
        // cout << "Case #" << c << ": ";
        solve(c);
        c++;
    }
    return 0;
}
/* UJJWAL KESHRI */
