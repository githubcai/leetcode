class Solution {
    struct Node{
        int sum, x, y;
        friend bool operator<(const Node &a, const Node &b){
            return a.sum > b.sum;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret;
        int size1 = nums1.size(), size2 = nums2.size();
        if(size1 == 0 || size2 == 0) return ret;
        priority_queue<Node> que;
        for(int i = 0; i < size1; ++i){
            Node node = {nums1[i] + nums2[0], i, 0};
            que.push(node);
        }
        while(k-- > 0 && !que.empty()){
            Node node = que.top();
            que.pop();
            ret.push_back(make_pair(nums1[node.x], nums2[node.y]));
            node.y += 1;
            if(node.y < size2){
                node.sum = nums1[node.x] + nums2[node.y];
                que.push(node);
            }
        }
        return ret;
    }
};
