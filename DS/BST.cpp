/************************ BST ***********************/

struct bst{
    int data;
    struct bst *left,*right;
};
struct bst* newd(){
    struct bst *ptr=(struct bst*) malloc(sizeof(struct bst));
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
struct bst* insert(struct bst *root,struct bst *temp){
    if(root==NULL){
        root=temp;return root;
    }
    if(temp->data>root->data){
        root->right=insert(root->right,temp);
    }
    else{
        root->left=insert(root->left,temp);
    }
    return root;
}
void postorder(struct bst *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(struct bst *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct bst *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelorder(struct bst *root){
    if(root==NULL) return;
    queue<struct bst*>qe;
    qe.push(root);
    struct bst *temp;
    while(!qe.empty()){
        temp=qe.front();qe.pop();
        cout<<temp->data<<" ";
        if(temp->left) qe.push(root->left);
        if(temp->right) qe.push(root->right);
    }
}
void mirror(struct bst *root){
    if(root==NULL) return;
    mirror(root->left);
    mirror(root->right);
    struct bst *ptr=root->left;
    root->left=root->right;
    root->right=ptr;
}

