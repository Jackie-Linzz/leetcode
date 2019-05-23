class Solution {
public:
    vector<int> mem;
    int climbStairs(int n) {
        if(n <= 1) return 1;
        if(mem.capacity() < n) mem.resize(n, 0);
        if(mem[n]) return mem[n];
        int r = climbStairs(n-1) + climbStairs(n-2);
        mem[n] = r;
        return r;
    }
};
