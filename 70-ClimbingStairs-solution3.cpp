// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
class Solution {
public:
    vector<int> mem;
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int> r(n+1);
        r[0] = r[1] = 1;
        for(int i = 2; i <= n; ++i) {
            r[i] = r[i-1] + r[i-2];
        }
        return r[n];
    }
};
