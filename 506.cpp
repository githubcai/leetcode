class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>> que;
        for(int i = 0; i < nums.size(); ++i) que.push(make_pair(nums[i], i));
        vector<string> ret(nums.size());
        int cnt = 1;
        while(!que.empty()){
            auto now = que.top();
            if(cnt < 4){
                switch(cnt){
                    case 1: ret[now.second] = "Gold Medal"; break;
                    case 2: ret[now.second] = "Silver Medal"; break;
                    case 3: ret[now.second] = "Bronze Medal"; break;
                }
            }else{
                stringstream ss;
                ss << cnt;
                ss >> ret[now.second];
            }
            que.pop();
            cnt += 1;
        }
        return ret;
    }
