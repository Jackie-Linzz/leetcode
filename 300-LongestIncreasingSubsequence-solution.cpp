//Runtime: 28 ms, faster than 63.81% of C++ online submissions for Longest Increasing Subsequence.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> status(nums.size(), 0);
        status[0] = 1;
        for(int i = 1; i < nums.size(); ++i) {
            int max = 0, length = 0;
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) length = status[j] + 1;
                else length = 1;
                if(length > max) max = length;
            }
            status[i] = max;
        }
        int result = 1;
        for(int e: status) {
            if(e > result) result = e;
        }
        return result;
    }
};
