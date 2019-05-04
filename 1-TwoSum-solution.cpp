// Runtime: 12 ms, faster than 88.33% of C++ online submissions for Two Sum.
// Memory Usage: 10.8 MB, less than 6.33% of C++ online submissions for Two Sum.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> temp;
        if(nums.size() < 2) return result;
        for(int i = 0; i < nums.size(); ++i) {
            temp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i) {
            auto it = temp.find(target - nums[i]);
            if(it != temp.end()) {
                if(i != it->second) {
                    result.push_back(i);
                    result.push_back(it->second);
                    break;
                }
            }
        }
        return result;
    }
};
