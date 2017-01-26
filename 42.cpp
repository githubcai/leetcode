class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, level = 0, left = 0, right = height.size() - 1;
        while(left <= right){
            int temp = height[height[left] < height[right] ? left++ : right--];
            level = max(level, temp);
            water += level - temp;
        }
        return water;
    }
};
