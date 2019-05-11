class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r;
        if(nums.size() < 3) return r;
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            if(val == 0) {
                if(m[val].size() < 3) m[val].push_back(i);
            } else {
                if(m[val].size() < 2) m[val].push_back(i);
            }
        }
        int index = 0;
        vector<int> num;
        for(auto it = m.begin(); it != m.end(); ++it) {
            auto &v = it->second;
            for(int i = 0; i < v.size(); ++i) {
                v[i] = index;
                ++index;
                num.push_back(it->first);
            }
        }
        for(int i = 0; i < num.size()-2; ++i) {
            for(int j = i+1; j < num.size()-1; ++j) {
                auto it = m.find(0-num[i]-num[j]);
                if(it != m.end()) {
                    vector<int>&v = it->second;
                    if(v[v.size()-1] > j) {
                        vector<int> t({num[i], num[j], it->first});
                        r.push_back(t);
                    }
                }
                while(num[j] == num[j+1]) ++j;
            }
            while(num[i] == num[i+1]) ++i;
        }
            
        return r;
    }
};
