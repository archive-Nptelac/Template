const int K=26;
class Node{
public:
    int eow=0;
    Node* child[K];
    Node(){
        eow=0;
        for(int i=0;i<K;i++){
            child[i]=NULL;
        }
    }
};
class Trie{
    Node* root=new Node();
    void insert_string(string &s){
        int n=s.length();
        Node* cur=root;
        for(int i=0;i<n;i++){
            int id=s[i]-'a';
            if(!cur->child[id]){
                cur->child[id]=new Node();
            }
            cur=cur->child[id];
        }
        (cur->eow)++;
    }
    bool search(string &s){
        int n=s.length();
        Node* cur=root;
        for(int i=0;i<n;i++){
            int id=s[i]-'a';
            if(!cur->child[id]) return false;
            cur=cur->child[id];
        }
        if(cur!=NULL && cur->eow!=0)    return true;
        return false;
    }
    Node* deleteword(Node* ptr,string &s,int id){
        if(ptr==NULL)   return NULL;
        int n=s.length();
        if(id==n){
            if(ptr->eow){
                ptr->eow=false;
            }
            bool ok=true;
            for(int i=0;i<26;i++){
                if(ptr->child[i])   ok=false;
            }
            if(ok){
                delete(ptr);
                ptr=NULL;
            }
            return ptr;
        }
        int sid=s[id]-'a';
        ptr->child[sid]=deleteword(ptr->child[sid],s,id+1);
        bool ok1=true;
        for(int i=0;i<26;i++){
            if(ptr->child[i])  ok1=false;
        }
        if(ok1 && (ptr->eow == false)){
            delete(ptr);
            ptr=NULL;
        }
        return ptr;
    }
public:
    void insert(string &s){
        insert_string(s);
    }
    bool is_present(string &s){
        return search(s);
    }
    void remove(string &s){
        if(!is_present(s)){
            return;
        }
        root=deleteword(root,s,0);
    }
};
