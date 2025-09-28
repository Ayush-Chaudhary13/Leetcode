class NumArray {
public:
    vector<int> segtree;
    int n;
    void build(int i, int l, int r, vector<int>&nums){
        if(l==r){
            segtree[i] = nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }

    void updateseg(int i, int l, int r, int index, int val){
        if(l ==r){
            segtree[i] = val;
            return;
        }
        int mid = l+(r-l)/2;

        if(index <= mid){
            updateseg(2*i+1,l,mid,index,val);
        }
        else updateseg(2*i+2,mid+1,r,index,val);

        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }

    int sum(int i, int l, int r, int left, int right){
        if(l > right || r < left) return 0;

        if( l>= left && r <= right) return segtree[i];

        int mid = l+(r-l)/2;

        return sum(2*i+1,l,mid,left,right) + sum(2*i+2,mid+1,r,left,right);
    }

    NumArray(vector<int>& nums) {
        if(nums.size()>0){
         n = nums.size();
        segtree.resize(4*n,0);
        build(0,0,n-1,nums);
        }  
    }
    
    void update(int index, int val) {
        if(n ==0) return;
         updateseg(0,0,n-1,index,val);    
    }
    
    int sumRange(int left, int right) {
        if(n==0) return 0;
        return sum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */