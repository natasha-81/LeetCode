class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for (auto interval:intervals) {
            //if first interval or non overlapping interval, add it to result
            if (merged.empty() || merged.back()[1] < interval[0]) { 
                merged.push_back(interval);
            }
            else {
                // if overlapping intervals, merge them
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};