class NumArray {
    vector<int> sum;
    int size;
    
    void pushUp(int root){
        sum[root] = sum[root << 1] + sum[root << 1 | 1];
    }
    
    void buildTree(int l, int r, int root, const vector<int> &nums){
        if(l == r){
            sum[root] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(l, mid, root << 1, nums);
        buildTree(mid + 1, r, root << 1 | 1, nums);
        pushUp(root);
    }
    
    void updateNode(int p, int v, int l, int r, int root){
        if(l == r){
            sum[root] = v;
            return;
        }
        int mid = (l + r) / 2;
        if(p <= mid) updateNode(p, v, l, mid, root << 1);
        if(p > mid) updateNode(p, v, mid + 1, r, root << 1 | 1);
        pushUp(root);
    }
    
    int queryRange(int L, int R, int l, int r, int root){
        if(L <= l && r <= R) return sum[root];
        int mid = (l + r) / 2, ret = 0;
        if(mid >= L) ret += queryRange(L, R, l, mid, root << 1);
        if(mid < R) ret += queryRange(L, R, mid + 1, r, root << 1 | 1);
        return ret;
    }
public:
    NumArray(vector<int> nums) {
        size = nums.size();
        if(size != 0){
            sum.resize(size << 2, 0);
            buildTree(0, size - 1, 1, nums);
        }
    }
    
    void update(int i, int val) {
        updateNode(i, val, 0, size - 1, 1);
    }
    
    int sumRange(int i, int j) {
        return queryRange(i, j, 0, size - 1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
