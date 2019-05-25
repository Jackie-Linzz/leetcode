// time limit exceeded
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return recurse(nums, INT_MIN, 0, 0);
    }
    int recurse(vector<int>& nums, int prev, int curpos, int l) {
        if(curpos == nums.size()) return l;
        int taken = 0, ntaken = 0;
        if(nums[curpos] > prev) taken = recurse(nums, nums[curpos], curpos+1, l+1);
        ntaken = recurse(nums, prev, curpos+1, l);
        return taken > ntaken ? taken : ntaken;
    }
};
