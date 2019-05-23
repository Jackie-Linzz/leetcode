//Runtime: 12 ms, faster than 94.95% of C++ online submissions for Edit Distance.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.size();
        int length2 = word2.size();
        if(length1 == 0) return length2;
        if(length2 == 0) return length1;
        int status[length1+1][length2+1];
        
        for(int i = 0; i <= length1; ++i) {
            status[i][0] = i;
        }
        
        for(int j = 0; j <= length2; ++j) {
            status[0][j] = j;
        }
        for(int i = 1; i <= length1; ++i)
            for(int j = 1; j <= length2; ++j) {
                int d1 = status[i-1][j] + 1;
                int d2 = status[i][j-1] + 1;
                int d3 = word1[i-1] == word2[j-1] ? status[i-1][j-1] : status[i-1][j-1]+1;
                int min = d1;
                if(d2 < min) min = d2;
                if(d3 < min) min = d3;
                status[i][j] = min;
            }
        return status[length1][length2];
    }
    
};
