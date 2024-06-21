// binary lifting function

void binaryLifting(ll root, ll par, vector<vector<ll>> &adj, vector<vector<ll>> &parent, vector<ll> &level)
{
    parent[root][0] = par;
    for (ll i = 1; i < 20; i++)
    {
        if (parent[root][i - 1] != -1)
        {
            parent[root][i] = parent[parent[root][i - 1]][i - 1];
        }
        else
            parent[root][i] = -1;
    }
    for (auto child : adj[root])
    {
        if (child == par)
            continue;
        level[child] = level[root] + 1;
        binaryLifting(child, root, adj, parent, level);
    }
}

// function to lift a node by k 
 
ll liftNode(ll node, ll k, vector<vector<ll>> &parent)
{
    for (ll i = 19; i >= 0; i--)
    {
        if (k == 0 || node == -1)
            return node;
        if (k >= (1 << i))
        {
            k -= (1 << i);
            node = parent[node][i];
        }
    }
    return node;
}

// to find the lca of two nodes

ll findLca(ll a, ll b, vector<ll> &level, vector<vector<ll>> &parent)
{
    ll la = level[a], lb = level[b];
    if (la > lb)
        swap(a, b);
    b = liftNode(b, abs(la - lb), parent);
    if (a == b)
        return a;
    for (ll i = 20; i >= 0; i--)
    {
        ll na = parent[a][i];
        ll nb = parent[b][i];
        if (na != nb)
        {
            a = na;
            b = nb;
        }
    }
    return parent[a][0];
}
