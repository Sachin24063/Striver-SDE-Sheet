class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size()-1;
        int leftmax = 0, rightmax = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= leftmax) leftmax = height[left];
                else ans += leftmax - height[left];
                left++;
            }
            else{
                if(height[right] >= rightmax) rightmax = height[right];
                else ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};
