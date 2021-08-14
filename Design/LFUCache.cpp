class LFUCache {
    const int cap;
    int minFreq;
    unordered_map<int, pair<int, int>> keyValFreq;                  // ma[key]={value,freq};
    unordered_map<int, list<int>> freqKey;                          // for a frequency f, stores all node as a doubly linked list
    unordered_map<int, list<int>::iterator> keyIter;                // stores address of a key

public:
    LFUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (keyValFreq.find(key) == keyValFreq.end())   return -1;  // If not found
        int freq = keyValFreq[key].second;                          // get cur freq
        freqKey[freq].erase(keyIter[key]);                          // erase cur freq from freq list
        freq++;                                                     // Increment the freq
        freqKey[freq].emplace_front(key);                           // put it in new freq list(f+1)
        keyIter[key] = freqKey[freq].begin();                       // Store its address
        keyValFreq[key].second = freq;                              // update freq
        
        if (freqKey[minFreq].empty()) minFreq = freq;               // update min frequency
        
        return keyValFreq[key].first;
    }

    void put(int key, int value) {
        if (cap <= 0) return;                                        // if cap<=0 no operation
        
        if (get(key) != -1) {                                       // cal get function to adjust freq
            keyValFreq[key].first = value;                          // If not present
            return;
        }

        if (keyValFreq.size() == cap) {
            int delKey = freqKey[minFreq].back();
            freqKey[minFreq].pop_back();
            keyValFreq.erase(delKey);
            keyIter.erase(delKey);
        }

        minFreq = 1;
        keyValFreq[key] = make_pair(value, minFreq);
        freqKey[minFreq].emplace_front(key);
        keyIter[key] = freqKey[minFreq].begin();
    }
};
