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
