//heap buffer overflow
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        vector<int> num(nums.begin(), nums.end());
        std::sort(num.begin(), num.end());
        for(int i = 0; i < num.size()-2; ++i) {
            if(i > 0 && num[i] == num[i-1]) continue;
            int l = i + 1;
            int r = num.size() - 1;
            while(l < r) {
                int val = num[i] + num[l] + num[r];
                if(val < 0) {
                    ++l;
                    continue;
                }
                else if(val > 0) {
                    --r;
                    continue;
                }
                else {
                    vector<int> t({num[i], num[l], num[r]});
                    result.push_back(t);
                    while(num[l] == num[l+1]) ++l;
                    while(num[r] == num[r-1]) --r;
                    ++l;
                    --r;
                }
            }
        }
        return result;
    }
};
