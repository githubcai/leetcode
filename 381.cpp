class RandomizedCollection {
    unordered_map<int, vector<int>> ref;
    vector<pair<int, int>> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto iter = ref.find(val);
        if(iter != ref.end()){
            iter->second.push_back(nums.size());
            nums.push_back(make_pair(val, iter->second.size() - 1));
            return false;
        }
        ref[val] = vector<int>(1, nums.size());
        nums.push_back(make_pair(val, 0));
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter = ref.find(val);
        if(iter == ref.end()) return false;
        auto temp = nums[iter->second.back()];
        ref[nums.back().first][nums.back().second] = iter->second.back();
        nums[iter->second.back()] = nums.back();
        iter->second.pop_back();
        if(iter->second.empty()) ref.erase(iter);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
