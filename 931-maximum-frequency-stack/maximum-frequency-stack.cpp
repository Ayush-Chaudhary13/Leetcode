class FreqStack {
public:
    map<int,int> freq;
    map<int, stack<int>> st;
    int maxi = 0;
    FreqStack() {} 

    void push(int val) {
        freq[val]++;
        st[freq[val]].push(val);
        maxi = max(maxi, freq[val]);
    }
    
    int pop() {

        int ans = st[maxi].top();

        st[maxi].pop();
        freq[ans]--;

        if(st[maxi].empty()) maxi--;

        return ans;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */