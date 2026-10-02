class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int left = 0;
        int right = height.size()-1;
        int leftmax = height[left];
        int rightmax = height[right];
        int res = 0;
        while (left<right) {
            if (leftmax < rightmax) {
                left++;
                leftmax = max(leftmax,height[left]);
                res += leftmax - height[left];
            }
            else {
                right--;
                rightmax = max(rightmax,height[right]);
                res += rightmax - height[right];
            }
        }
        return res;
    }
};