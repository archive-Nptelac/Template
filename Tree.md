# Tree

- [Binary Tree](#TraversalRecursive)
  - [Traversal Recursive](#TraversalRecursive)
  - [Traversal Iterative](#TraversalIterative)
  - [Traversal All](#TraversalAll)
  - [Max Depth](#MaxDepth)
  - [Balanced Binary Tree (Height Balanced Tree)](#BalancedBinaryTree)
  - [Diameter of Binary Tree](#Diameter)
  - [Maximum Path Sum in a Binary Tree](#MaxPathSum)
  - [Boundary Traversal of a Binary Tree](#BoundaryTraversal)
  - [Views of a Binary Tree](#TopView)
    - [Top view (Only Iterative, in recursive we need to store height as well)](#TopView)
    - [Bottom view (Only Iterative, in recursive we need to store height as well)](#BottomView)
    - [Right view (Recursive)](#RightView)
    - [Left view (Recursive)](#LeftView)
  - [Path from source node to given node](#PathSourceDestination)
  - [Lowest Common Ancestor of Binary Tree](#LCA)
  - [Width of Binary Tree](#Width)
  - [Children Sum property](#MakeChildrenSum)
  - [Create Tree from given Traversal](#InPre)
    - [Using Inorder and Preorder Traversal (It is Unique)](#InPre)
    - [Using Inorder and Postorder Traversal (It is Unique)](#InPost)
    - [Using Preorder and Postorder Traversal (It is not unique)](#PrePost)
  - [Morris Traversal](#InMorris)
    - [Inorder using Morris](#InMorris)
    - [Preorder using Morris](#PreMorris)
- [Binary Search Tree](#BinarySearchTree)


## TraversalRecursive
```
	void inorder_traverse(Node* cur){
	    if(!cur)    return;
	    if(cur->left)   inorder_traverse(cur->left);
	    cout << (cur->data) << " ";
	    if(cur->right)  inorder_traverse(cur->right);
	}
	void preorder_traverse(Node* cur){
	    if(!cur)    return;
	    cout << (cur->data) << " ";
	    if(cur->left)   preorder_traverse(cur->left);
	    if(cur->right)  preorder_traverse(cur->right);
	}
	void postorder_traverse(Node* cur){
	    if(!cur)    return;
	    if(cur->left)   postorder_traverse(cur->left);
	    if(cur->right)  postorder_traverse(cur->right);
	    cout << (cur->data) << " ";
	}
	void levelorder_traverse(vector<int>&res,Node* cur){
	    if(!cur)   return;
	        queue<Node*>qe;
	        qe.push(cur);
	        while(!qe.empty()){
	            int t=qe.size();
	            while(t--){
	                cur=qe.front();
	                qe.pop();
	                res.push_back(cur->data);
	                if(cur->left)   qe.push(cur->left);
	                if(cur->right)  qe.push(cur->right);
	            }
	        }
    }

```


## TraversalIterative
```
	vector<int> inorder_iterative(TreeNode* root) {
        vector<int>ans;
        if(root == NULL)    return ans;
        
        stack<TreeNode*>st;
        TreeNode *curr = root;
        
        while(true){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
    }
    vector<int> preorder_iterative(TreeNode* root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode *curr = st.top();
            st.pop();
            
            ans.push_back(curr->val);
            // first push right node into the stack then left node, as we have to access first left one then right (so left should be on the top)
            if(curr->right) st.push(curr->right);
            if(curr->left)  st.push(curr->left);
        }
        
        return ans;
    }
    void postorder_iterative(vector<int>&res,Node* cur){
        // using 2 stack
        if(!cur)    return;
        stack<Node*>st1,st2;
        st1.push(cur);
        Node* tmp;
        while(!st1.empty()){
            tmp=st1.top();
            st1.pop();
            st2.push(tmp);
            if(tmp->left)   st1.push(tmp->left);
            if(tmp->right)  st1.push(tmp->right);
        }
        while(!st2.empty()){
            tmp=st2.top();
            st2.pop();
            res.push_back(tmp->data);
        }
    }
    void postorder_iterative1(vector<int>&res,Node* cur){
        // using 1 stack
        if(!cur)    return;
        stack<Node*>st;
        do{
            while(cur!=NULL){
                if(cur->right)  st.push(cur->right);
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            // If poped node has a right child and is not processed yet, then first process it then current node
            if((curr->right!=NULL) && (!st.empty()) && (st.top()==curr->right)){
                st.pop();
                st.push(cur);
                cur=cur->right;
            }
            else{
                res.push_back(root->data);
                cur=NULL;
            }
        }while(!st.empty());
    }

```


## TraversalAll
```
	void TraverseAll(TreeNode *root){
		if(root == NULL) return;

	    stack<pair<TreeNode*,int>> st; 
        st.push({root, 1}); 
        vector<int> pre, in, post;

        while(!st.empty()) {
            auto it = st.top(); 
            st.pop(); 

            // this is part of pre
            // increment 1 to 2 
            // push the left side of the tree
            if(it.second == 1) {
                pre.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
                }
            }

            // this is a part of in 
            // increment 2 to 3 
            // push right 
            else if(it.second == 2) {
                in.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
                }
            }
            // don't push it back again 
            else {
                post.push_back(it.first->val); 
            }
        }
	}

```


## MaxDepth
```
	int maxDepth(TreeNode *root){
		if(root==NULL)	return 0;
		if(root->left == NULL && root->right==NULL)	return 1;
		return 1+max(maxDepth(root->left),maxDepth(root->right));
	}

```


## BalancedBinaryTree
```
	// At each node difference of left height and right height should not be more that 1;
	// so my function will return -1 if it is not balanced,
	int height(TreeNode* root){
        if(root==NULL)  return 0;
        if(root->left==NULL && root->right==NULL)   return 1;
        int lh = height(root->left);
        if(lh==-1)  return -1;
        int rh = height(root->right);
        if(rh==-1)  return -1;
        if(abs(lh-rh)>1)    return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        if(h==-1)   return false;
        return true;
    }

```


## Diameter
```
	// as the diameter is just the sum of left height and right height at each node;
	// so just traverse over each node and find its left and right height and maximize the answer;
	int diameter(TreeNode *root,int &ans){
        if(root==NULL)  return 0;
        int lh = diameter(root->left,ans);
        int rh = diameter(root->right,ans);
        ans = max(ans, lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;
        int ans = 0;
        diameter(root,ans);
        return ans;
    }

```


## MaxPathSum
```
    int dfs(TreeNode *root, int &ans){
        if(root==NULL)  return 0;
        if(root->left==NULL && root->right==NULL){
            ans = max(ans, root->val);
            return root->val;
        }
        int ls = dfs(root->left,ans);
        int rs = dfs(root->right,ans);
        ls = max(ls, 0);
        rs = max(rs, 0);
        int curr = max({0,ls,rs,ls+rs});
        ans = max(ans, curr+root->val);
        return root->val + max({0,ls,rs});
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root,ans);
        return ans;
    }

```


## BoundaryTraversal
```
    void leftTraverse(Node *root, vector<int>&v){
        if(root==NULL)  return;
        if(root->left==NULL && root->right==NULL)   return;
        v.push_back(root->data);
        if(root->left)  root = root->left;
        else    root = root->right;
        leftTraverse(root,v);
    }
    void Inorder(Node *root, vector<int>&v){
        if(root==NULL)  return;
        Inorder(root->left,v);
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
        }
        Inorder(root->right,v);
    }
    void rightTraverse(Node *root, stack<int>&st){
        if(root==NULL)  return;
        if(root->left==NULL && root->right==NULL)   return;
        st.push(root->data);
        if(root->right) root = root->right;
        else    root = root->left;
        rightTraverse(root, st);
    }
    vector <int> printBoundary(Node *root)
    {
        // 1. root val then,
        // 2. Left boundary then,
        // 3. Leaf node finally,
        // 4. Right boundary
        vector<int>v;
        if(root==NULL)  return v;
        v.push_back(root->data);
        leftTraverse(root->left,v);
        Inorder(root,v);
        stack<int>st;
        rightTraverse(root->right,st);
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }

```


## TopView
```
    vector<int> topView(Node *root)
    {
        vector<int>res;
        if(root==NULL)  return res;

        queue<pair<Node*,int> >qe;
        map<int,int>ma;

        qe.push({root,0});
        while(!qe.empty()){
            auto pa = qe.front();
            qe.pop();
            Node *curr = pa.first;
            int cx = pa.second;
            if(ma.find(cx)==ma.end()){
                ma[cx] = curr->data;
            }
            if(curr->left)  qe.push({curr->left, cx-1});
            if(curr->right) qe.push({curr->right,cx+1});
        }

        for(auto it : ma){
            res.push_back(it.second);
        }
        return res;
    }

```


## BottomView
```
    vector <int> bottomView(Node *root) {
        vector<int>res;
        if(root==NULL)  return res;
        
        queue<pair<Node*,int> >qe;
        map<int,int>ma;
        
        qe.push({root,0});
        while(!qe.empty()){
            Node *curr = qe.front().first;
            int cx = qe.front().second;
            qe.pop();
            ma[cx] = curr->data;
            if(curr->left)  qe.push({curr->left,cx-1});
            if(curr->right) qe.push({curr->right,cx+1});
        }
        
        for(auto it : ma){
            res.push_back(it.second);
        }
        return res;
    }

```


## RightView
```
    void traverse(Node *root,vector<int>&res,int &req_level,int cur_level) {
        if(root==NULL)  return;
        if(req_level == cur_level){
            res.push_back(root->data);
            req_level++;
        }
        traverse(root->right,res,req_level,cur_level+1);
        traverse(root->left,res,req_level,cur_level+1);
    }
    vector<int> rightView(Node *root)
    {
        vector<int>res;
        if(root==NULL)   return res;
        int req_level = 0;
        traverse(root,res,req_level,0);
        return res;
    }
    // Iterative can be solved using level order traversal and line concept but in recursive avg case space complexity is O(H);

```


## LeftView
```
    void traverse(Node *root, vector<int>&res, int cur_level, int &req_level){
        if(root == NULL)  return;
        if(req_level == cur_level){
            res.push_back(root->data);
            req_level++;
        }
        traverse(root->left, res, cur_level+1, req_level);
        traverse(root->right, res, cur_level+1, req_level);
    }
    vector<int> leftView(Node *root)
    {
        vector<int>res;
        int req_level = 0;
        traverse(root,res,0,req_level);
        return res;
    }
    // Iterative can be solved using level order traversal and line concept but in recursive avg case space complexity is O(H);

```


## PathSourceDestination
```
    bool dfs(TreeNode *root, int B, vector<int>&res) {
        if(root==NULL)  return false;
        res.push_back(root->val);
        if(root->val == B){
            return true;
        }
        if(dfs(root->left,B,res) || dfs(root->right,B,res)){
            return true;
        }
        res.pop_back();
        return false;
    }
    vector<int> findPath(TreeNode* root, int B) {
        vector<int>res;
        if(A==NULL) return res;
        dfs(A,B,res);
        return res;
    }

```


## LCA
```
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)  return NULL;
        if(root==p || root==q){
            return root;
        }
        TreeNode* rightLCA=lowestCommonAncestor(root->right,p,q);
        TreeNode* leftLCA=lowestCommonAncestor(root->left,p,q);
        if(leftLCA!=NULL && rightLCA!=NULL){
            return root;
        }
        else if(leftLCA!=NULL){
            return leftLCA;
        }
        else if(rightLCA!=NULL){
            return rightLCA;
        }
        return NULL;
    }

```


## Width
```
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)    return 0;
        int ans = 0;
        queue<pair<TreeNode*,int> >qe;
        qe.push({root,0});
        
        while(!qe.empty()){
            auto pa = qe.front();
            TreeNode *curr = pa.first;
            int start = pa.second;
            int id1=0,id2=0;
            int s = qe.size();
            for(int i=0;i<s;i++){
                auto p = qe.front();
                qe.pop();
                if(i==0)    id1 = p.second;
                else if(i == s-1)   id2 = p.second;
                if(p.first->left != NULL){
                    qe.push({p.first->left, 2*(p.second-start)+1});
                }
                if(p.first->right != NULL){
                    qe.push({p.first->right, 2*(p.second-start)+2});
                }
            }
            ans = max(ans, id2-id1+1);
        }
        return ans;
    }

```


## MakeChildrenSum
```
    void reorder(TreeNode *root){
        if(root == NULL)    return;
        int child = 0;
        if(root->left)  child += (root->left->val);
        if(root->right) child += (root->right->val);

        if(child >= root->data){
            root->data = child;
        }
        else{
            if(root->left)  root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }

        reorder(root->left);
        reorder(root->right);

        int total = 0;
        if(root->left)  total += (root->left->val);
        if(root->right) total += (root->right->val);

        if(root->left || root->right)   root->val = total;
    }
    void changeTreeChildrenSum(TreeNode *root){
        reorder(root);
    }

```


## InPre
```
    unordered_map<int,int>idIn;
    int pre;
    TreeNode* fun(int l,int r,vector<int>& preorder, vector<int>& inorder) {
        if(l>r){
            return NULL;
        }
        if(l==r){
            TreeNode *root = new TreeNode(preorder[pre++]);
            return root;
        }
        int x = preorder[pre++];
        TreeNode *root = new TreeNode(x);
        root->left = fun(l,idIn[x]-1,preorder,inorder);
        root->right = fun(idIn[x]+1,r,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idIn.clear();
        for(int i=0;i<inorder.size();i++){
            idIn[inorder[i]]=i;
        }
        pre=0;
        return fun(0,inorder.size()-1,preorder,inorder);
    }

```


## InPost
```
    unordered_map<int,int>inId;
    int post;
    TreeNode* fun(int l,int r,vector<int>& inorder, vector<int>& postorder){
        if(l>r){
            return NULL;
        }
        if(l==r){
            TreeNode *root = new TreeNode(postorder[post--]);
            return root;
        }
        int x = postorder[post--];
        TreeNode *root = new TreeNode(x);
        root->right = fun(inId[x]+1,r,inorder,postorder);
        root->left = fun(l,inId[x]-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inId.clear();
        for(int i=0;i<inorder.size();i++){
            inId[inorder[i]]=i;
        }
        post=inorder.size()-1;
        return fun(0,inorder.size()-1,inorder,postorder);
    }

```


## PrePost
```
    eg::  pre[] = {1,2,3},  post[] = {3,2,1};
        1       1
       /       /
      2       2
     /         \
    3           3
    here both the tree has pre[] = {1,2,3} and post[] = {3,2,1}; so it is not unique;

    unordered_map<int,int>index;
    void storeIndex(vector<int>&v){
        int id=0;
        for(int x:v){
            index[x]=id;id++;
        }
    }
    TreeNode* construct(vector<int>&pre,vector<int>&post,int l1,int r1,int l2,int r2){
            TreeNode* tmp=new TreeNode(pre[l1]);
            if(l1==r1)  return tmp;
            int nxt=pre[l1+1];
            int postId=index[nxt];
            int rem=postId-l2+1;
            tmp->left=construct(pre,post,l1+1,l1+rem,l2,l2+rem-1);
            if(postId+1==r2)    return tmp;
            tmp->right=construct(pre,post,l1+rem+1,r1,postId+1,r2-1);
            return tmp;
    }
    TreeNode* constructFromPrePost(vector<int>& preOrder, vector<int>& postOrder) {
            storeIndex(postOrder);
            const int n=preOrder.size();
            return construct(preOrder,postOrder,0,n-1,0,n-1);
    }

```


## InMorris
```
    // In morris traversal the space complexity is O(1), and time complexity is O(n);
    vector<int> getInorder(TreeNode *root){
        vector<int>inorder;
        TreeNode *curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }

```


## PreMorris
```
    // In morris traversal the space complexity is O(1), and time complexity is O(n);
    vector<int> getPnorder(TreeNode *root){
        vector<int>preorder;
        TreeNode *curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }

```


# BinarySearchTree
```
will be added ...
```
