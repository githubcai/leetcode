class Solution {
    struct Node{
        int num, cnt;
        Node(int _num, int _cnt) : num(_num), cnt(_cnt){}
        friend bool operator<(const Node &a, const Node &b){
            return a.cnt < b.cnt;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int i = 0; i < nums.size(); ++i) cnt[nums[i]] += 1;
        priority_queue<Node> que;
        for(auto iter = cnt.begin(); iter != cnt.end(); ++iter){
            Node temp(iter->first, iter->second);
            que.push(temp);
        }
        vector<int> ret;
        while(k-- > 0){
            ret.push_back((que.top()).num);
            que.pop();
        }
        return ret;
    }
};
