#include<bits/stdc++.h>
using namespace std;
#define int long long int

class binaryTree{
private:
    class Node{
    public:
        int data;
        Node *left,*right;
        Node(){
            data=-1;
            left=NULL;
            right=NULL;
        }
        Node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
    };

    // Create root Node
    Node* root;

    Node* insertNode_(Node* cur,int x){
        if(cur==NULL){
            cur=new Node(x);
            return cur;
        }
        queue<Node*>qe;
        qe.push(cur);
        while(!qe.empty()){
            Node* tmp=qe.front();
            qe.pop();
            if(tmp->left)   qe.push(tmp->left);
            else{
                tmp->left=new Node(x);
                return cur;
            }
            if(tmp->right)  qe.push(tmp->right);
            else{
                tmp->right=new Node(x);
                return cur;
            }
        }
        return cur;
    }
    // Recursive Traversal
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
    // Iterative Traversal
    void inorder_iterative(vector<int>&res,Node* cur){
        if(!root)  return;
        stack<Node*>st;
        while(st.empty()==false || cur!=NULL){
            while(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();st.pop();
            res.push_back(cur->data);
            cur=cur->right;
        }
    }
    void preorder_iterative(vector<int>&res,Node* cur){
        if(!cur)    return;
        stack<Node*>st;
        while(st.empty()==false || cur!=NULL){
            while(cur!=NULL){
                st.push(cur);
                res.push_back(cur->data);
                cur=cur->left;
            }
            cur=st.top();st.pop();
            cur=cur->right;
        }
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
            if((cur->right!=NULL) && (st.top()==cur->right)){
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
public:
    binaryTree(){ root=NULL; }
    void insertNode(int x){ root=insertNode_(root,x); }
    void inorder(){ inorder_traverse(root); }
    void preorder(){ preorder_traverse(root); }
    void postorder(){ postorder_traverse(root); }
    vector<int> levelorder(){
        vector<int>res;
        levelorder_traverse(res,root);
        return res;
    }
    vector<int> inorder_iterative(){
        vector<int>res;
        inorder_iterative(res,root);
        return res;
    }
    vector<int> preorder_iterative(){
        vector<int>res;
        preorder_iterative(res,root);
        return res;
    }
    vector<int> postorder_iterative(){
        vector<int>res;
        postorder_iterative(res,root);
        return res;
    }
};

int32_t main(){

    binaryTree bt;
    int t;
    cin >> t;
    // t=7, {10,11,9,7,12,5,8};
    while(t--){
        int x;
        cin >> x;
        bt.insertNode(x);
    }
    vector<int>v1=bt.inorder_iterative();
    vector<int>v2=bt.preorder_iterative();
    vector<int>v3=bt.postorder_iterative();
    vector<int>v4=bt.levelorder();
    bt.inorder();cout<<endl;
    for(int x:v1)   cout<<x<<" ";cout<<endl;
    bt.preorder();cout<<endl;
    for(int x:v2)   cout<<x<<" ";cout<<endl;
    bt.postorder();cout<<endl;
    for(int x:v3)   cout<<x<<" ";cout<<endl;
    for(int x:v4)   cout<<x<<" ";cout<<endl;
    return 0;
}
