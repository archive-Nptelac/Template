#include<bits/stdc++.h>
using namespace std;

#define int long long int

class AvlTree {
private:
	class Node {
	public:
		int val;
		Node *left;
		Node *right;
		Node(int x){
			val=x;
			left=NULL;
			right=NULL;
		}
		Node(){  }
	};
	// create a root node;
	Node *root;
    int height(Node* ptr) {
        if(!ptr)    return 0;
        return 1+max(height(ptr->left),height(ptr->right));
    }
    int difference(Node* ptr) {
        return height(ptr->left)-height(ptr->right);
    }
    Node* ll_rotation(Node* ptr) {
        Node *tmp;
        tmp=ptr->left;
        ptr->left=tmp->right;
        tmp->right=ptr;
        return tmp;
    }
    Node* rr_rotation(Node* ptr) {
        Node *tmp;
        tmp=ptr->right;
        ptr->right=tmp->left;
        tmp->left=ptr;
        return tmp;
    }
    Node* lr_rotation(Node* ptr) {
        Node *tmp;
        tmp=ptr->left;
        ptr->left=rr_rotation(tmp);
        return ll_rotation(ptr);
    }
    Node* rl_rotation(Node* ptr) {
        Node *tmp;
        tmp=ptr->right;
        ptr->right=ll_rotation(tmp);
        return rr_rotation(ptr);
    }
    Node* balance(Node* ptr) {
        int bf=difference(ptr);
        if(bf>=2){
            int bfl=difference(ptr->left);
            if(bfl>0) {
                ptr=ll_rotation(ptr);
            }
            else {
                ptr=lr_rotation(ptr);
            }
        }
        else if(bf<=-2){
            int bfr=difference(ptr->right);
            if(bfr>0) {
                ptr=rl_rotation(ptr);
            }
            else {
                ptr=rr_rotation(ptr);
            }
        }
        return ptr;
    }
	Node* insert_node_(Node* ptr,int x) {
		if(ptr==NULL){
			ptr=new Node(x);
			return ptr;
		}
		else if(x>=(ptr->val)){
			ptr->right=insert_node_(ptr->right,x);
			ptr=balance(ptr);
		}
		else if(x<(ptr->val)){
			ptr->left=insert_node_(ptr->left,x);
			ptr=balance(ptr);
		}
		return ptr;
	}
    void inorder_(Node* ptr) {
        if(!ptr)    return;
        inorder_(ptr->left);
        cout << (ptr->val) << " ";
        inorder_(ptr->right);
    }
    void preorder_(Node* ptr) {
        if(!ptr)    return;
        cout << (ptr->val) << " ";
        preorder_(ptr->left);
        preorder_(ptr->right);
    }
    void postorder_(Node* ptr) {
        if(!ptr)    return;
        postorder_(ptr->left);
        postorder_(ptr->right);
        cout << (ptr->val) << " ";
    }
    void show_(Node* ptr, int lvl) {
        int id;
        if(ptr==NULL)   return;
        show_(ptr->right,lvl+1);
        cout << " ";
        if(ptr==root){
            cout << "ROOT-> ";
        }
        for(int i=0;i<lvl && ptr!=root;i++) {
            cout << " ";
            cout << ptr->val;
            show_(ptr->left,lvl+1);
        }
    }
public:
	AvlTree() { root=NULL; }
	void insert_node(int x){ root=insert_node_(root,x); }
    bool is_empty() { return (root==NULL); }
    void inorder() { 
        cout << "Inorder: ";
        inorder_(root);
        cout << endl;
    }
    void preorder() { 
        cout << "preorder: ";
        preorder_(root);
        cout << endl;
    }
    void postorder() { 
        cout << "postorder: ";
        postorder_(root);
        cout << endl;
    }
    void show() {
        show_(root,1);
        cout << endl;
    }
};


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    AvlTree avl;
    int c,x;
    int query;
    cin >> query;
    while (query--) {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.show Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> x;
                avl.insert_node(x);
                break;
            case 2:
                if (avl.is_empty()) {
                    cout << "Tree is Empty" << endl;
                    continue;
                }
                cout << "Balanced AVL Tree:" << endl;
                avl.show();
                break;
            case 3:
                cout << "Inorder Traversal:" << endl;
                avl.inorder();
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal:" << endl;
                avl.preorder();
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal:" << endl;
                avl.postorder();
                cout << endl;
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
/* UJJWAL KESHRI */
