#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Implementation of LRU Cache

class LRUCache{
    public:
        class node{
            public:
                int key,val;
                node *prev,*next;
                node(){
                    key=0;val=0;
                }
                node(int k,int v){
                    key=k;val=v;
                }
        };

        node* head = new node(-1,-1);
        node* tail = new node(-1,-1);
        int cap;
        unordered_map<int,node*>ma;

        LRUCache(int size){
            cap=size;
            head->next=tail;
            tail->prev=head;
        }

        LRUCache(){
            cap=3;                                          // Just taking a random value
            head->next=tail;
            tail->prev=head;
        }

        void addnode(node *ptr){
            node *temp=head->next;
            ptr->next=temp;
            ptr->prev=head;
            head->next=ptr;
            temp->prev=ptr;
        }

        void deletenode(node *ptr){
            node *ptr_prv=ptr->prev;
            node *ptr_nxt=ptr->next;
            ptr_prv->next=ptr_nxt;
            ptr_nxt->prev=ptr_prv;
        }

        int get(int key_){
            if(ma.find(key_)==ma.end())  return -1;         // If not found in map then return -1
            node *ptr=ma[key_];                             // get the address of the key
            ma.erase(key_);                                 // erase it from map
            int res=ptr->val;                               // result to return
            deletenode(ptr);                                // delete it from its position
            addnode(ptr);                                   // then add it at front (making it last recently used)
            ma[key_]=head->next;                            // store it's new address
            return res;                                     // return result
        }

        void put(int key_,int val_){
            node *ptr;
            if(ma.find(key_)!=ma.end()){                    // delete existing node
                ptr=ma[key_];
                ma.erase(key_);
                deletenode(ptr);
            }
            if(ma.size()==cap){                             // If capacity is full then delete least recently used
                ptr=tail->prev;
                ma.erase(tail->prev->key);
                deletenode(tail->prev);
            }
            ptr=new node(key_,val_);                        // becomes last recently used
            addnode(ptr);
            ma[key_]=head->next;
        }
};

int32_t main(){
    int size,t,k,v;
    string query;
    cout << "size: ";
    cin >> size;
    cout << "null" << endl << "No of query: ";
    cin >> t;
    LRUCache lru(size);
    while(t--){
        cout << "Query: ";
        cin >> query;
        if(query=="put"){
            cin >> k >> v;
            lru.put(k,v);
            cout << "null" << endl;
        }
        else{
            cin >> k;
            cout << lru.get(k) << endl;
        }
    }
    return 0;
}


// Input
// ["LRUCache", "put", "put",  "get", "put", "get", "put", "get", "get", "get"]
// [[2],        [1, 1], [2, 2], [1],  [3, 3], [2],  [4, 4], [1],   [3],   [4]]
// Output
// [null,        null,    null,  1,    null,  -1,    null,  -1,     3,     4]


