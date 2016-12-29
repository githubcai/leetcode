class Solution {
    vector<int> hou, hea;
public:
    bool check(int mid){
        for(int i = 0, j = 0; i < hea.size(); ++i){
            int l = hea[i] - mid, r = hea[i] + mid;
            while(j < hou.size() && hou[j] >= l && hou[j] <= r) ++j;
            if(j == hou.size()) return true;
        }
        return false;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        hou.resize(houses.size()), hea.resize(heaters.size());
        copy(houses.begin(), houses.end(), hou.begin());
        copy(heaters.begin(), heaters.end(), hea.begin());
        sort(hou.begin(), hou.end());
        sort(hea.begin(), hea.end());
        int ans = 0, left = 0, right = 1000000000;
        while(left <= right){
            int mid = (left + right) / 2;
            if(check(mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
