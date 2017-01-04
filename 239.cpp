class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            while(!que.empty() && que.front() <=  i - k) que.pop_front();
            while(!que.empty() && nums[que.back()] < nums[i]) que.pop_back();
            que.push_back(i);
            if(i >= k - 1) ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};
