class LFUCache {
public:
    class node{                                         // create a node for doubly linked list
    public:
        int key,val,cnt;
        node *prev,*next;
        node(){
            key = -1; val = -1; cnt = 1;
            prev = NULL; next = NULL;
        }
        node(int a,int b){
            key = a; val = b; cnt = 1;                  // initially count should be 1( current frequency of this key-value pair)
            prev = NULL; next = NULL;
        }
    };
    class List{                                         // create Doubly linked list
    public:
        int size;
        node *head,*tail;
        List(){
            size = 0;
            head = new node(-1,-1);
            tail = new node(-1,-1);
            head->next = tail;
            tail->prev = head;
        }
        void addNode(node *ptr){
            size++;
            node *tmp = head->next;
            ptr->next = tmp;
            tmp->prev = ptr;
            ptr->prev = head;
            head->next = ptr;
        }
        void removeNode(node *ptr){
            size--;
            node *ptr_next = ptr->next;
            node *ptr_prev = ptr->prev;
            ptr_prev->next = ptr_next;
            ptr_next->prev = ptr_prev;
            ptr->next = NULL;
            ptr->prev = NULL;
            // delete(ptr);
        }
    };
    
    int minfreq, maxsize, cursize;
    map<int,node*>keyNode;
    map<int,List*>freqList;
    
    LFUCache(int capacity) {
        maxsize = capacity;
        minfreq = 0;
        cursize = 0;
        keyNode.clear();
        freqList.clear();
    }
    
    // to update frequency Map we have to first delete keynode than find the list in which this node is present(ptr->cnt) and delete it from there
    // after that find next higher list, if it is not present create one and update freq of this current node
    // and then add this node in the new higher freq list at the front, and update keynode and freqlist of it
  
    void updatefrequencyMap(node *ptr){
        keyNode.erase(ptr->key);
        List *tmpList = freqList[ptr->cnt];
        tmpList->removeNode(ptr);
        
        if((ptr->cnt == minfreq) && (tmpList->size == 0)){
            minfreq++;
        }
        
        List *nextList = new List();
        if(freqList.find(ptr->cnt + 1) != freqList.end()){
            nextList = freqList[ptr->cnt + 1];
        }
        
        (ptr->cnt)++;
        nextList->addNode(ptr);
        freqList[ptr->cnt] = nextList;
        keyNode[ptr->key] = ptr;
    }
    
    // if the key is not present in the keynode then return -1
    // else find the node pointer and from it its value after that update its frequency as it is used one more time and return value
    
    int get(int k) {
        if(keyNode.find(k) == keyNode.end()){
            return -1;
        }
        node *tmpNode = keyNode[k];
        int v = tmpNode->val;
        updatefrequencyMap(tmpNode);
        return v;
    }
  
    // if maxsize of cache is 0 then we can't put any item so return at the very begining
    // now if this node is already present then update its value and then its frequency as it is used one more time and finally return
    // but if not present previously, and cache is full, so find list of minimum frequency and from this list delete the last node(LRU one) and that last node from the keynode map as well and decrease the cursize as well
    // now put the current pair by creating a new node and update minimum freq to 1, now check if 1 freq list already exist or not, if exist then add new node at the front
    // else create a new list and add this new node at the front and update keyNode and freqList;
    
    void put(int k, int v) {
        if(maxsize == 0){
            return;
        }
        
        if(keyNode.find(k) != keyNode.end()){
            node *ptr = keyNode[k];
            ptr->val = v;
            updatefrequencyMap(ptr);
            return;
        }
        
        if(maxsize == cursize){
            List *tmpList = freqList[minfreq];
            node *tmpNode = tmpList->tail->prev;
            keyNode.erase(tmpNode->key);
            tmpList->removeNode(tmpNode);
            cursize--;
        }
        
        cursize++;
        minfreq = 1;
        List *tmpList = new List();
        if(freqList.find(minfreq) != freqList.end()){
            tmpList = freqList[minfreq];
        }
        
        node *tmpNode = new node(k,v);
        tmpList->addNode(tmpNode);
        keyNode[k] = tmpNode;
        freqList[minfreq] = tmpList;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
