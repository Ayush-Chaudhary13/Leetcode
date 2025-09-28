struct node{
    int s,e;
    node* left, *right;
    node(int s, int e): s(s), e(e), left(NULL), right(NULL){}
};
class MyCalendar {
    node* root;
public:
    MyCalendar(): root(NULL) {}

    bool dfs(int s, int e, node* &curr){
        if(!curr){
            curr = new node(s,e);
            return 1;
        }

        if(e <= curr->s) return dfs(s,e,curr->left);
        else if(s >= curr->e) return dfs(s,e,curr->right);
        else return 0;
    }
    
    bool book(int s, int e) {
       return dfs(s,e,root);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */