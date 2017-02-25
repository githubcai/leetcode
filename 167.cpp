class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> ret;
        while(left < right){
            int temp = numbers[left] + numbers[right];
            if(temp == target){
                ret.push_back(left + 1);
                ret.push_back(right + 1);
                break;
            }
            if(temp < target){
                left += 1;
            }else{
                right -= 1;
            }
        }
        return ret;
    }
};
