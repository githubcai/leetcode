class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for(int num : nums1) set1.insert(num);
        for(int num : nums2) set2.insert(num);
        vector<int> ret;
        for(auto iter = set2.begin(); iter != set2.end(); ++iter){
            if(set1.find(*iter) != set1.end()) ret.push_back(*iter);
        }
        return ret;
    }
};
