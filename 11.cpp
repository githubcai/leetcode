class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, vleft = height[left], vright = height[right];
        int ret = min(vleft, vright) * (right - left);
        while(left < right){
            if(vleft <= vright){
                while(left < right){
                    if(vleft < height[left]){
                        int t = min(height[left], height[right]) * (right - left);
                        if(t > ret){
                            ret = t;
                            break;
                        }
                        if(height[left] > vright){
                            vleft = height[left];
                            break;
                        }
                    }
                    ++left;
                }
            }else{
                while(left < right){
                    if(vright < height[right]){
                        int t = min(height[left], height[right]) * (right - left); 
                        if(t > ret){
                            ret = t;
                            break;
                        }
                        if(height[right] > vleft){
                            vright = height[right];
                            break;
                        }
                    }
                    --right;
                }
            }
        }
        return ret;
    }
};
