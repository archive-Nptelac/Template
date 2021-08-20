class MyCircularDeque {
    vector<int>dq;
    int front,rear,cnt,cap;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        dq.resize(k,-1);
        cnt=0;cap=k;front=0;rear=k-1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(cnt==cap)    return false;
        dq[front]=value;
        cnt++;
        front++;front%=cap;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(cnt==cap)    return false;
        dq[rear]=value;
        cnt++;
        rear--;rear+=cap;rear%=cap;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(cnt==0)  return false;
        front--;front+=cap;front%=cap;cnt--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(cnt==0)  return false;
        rear++;rear%=cap;cnt--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(cnt==0)  return -1;
        return dq[(front-1+cap)%cap];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(cnt==0)  return -1;
        return dq[(rear+1)%cap];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (cnt==0);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (cnt==cap);
    }
};
