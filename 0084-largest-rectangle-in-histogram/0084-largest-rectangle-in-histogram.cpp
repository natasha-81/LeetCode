class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for (int i=0; i<=n; i++) {
            while (!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                // if current bar is shorter then calculate stack's top area because it cannot be extended further
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                maxArea = max(maxArea, (height * width));
            }
            st.push(i);
        }
        return maxArea;
    }
};