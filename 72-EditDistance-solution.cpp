class Solution {
public:
    int minDistance(string word1, string word2) {
        return recurse(word1, word1.size(), word2, word2.size(), 0, 0, 0);
    }
    int recurse(string word1, int length1, string word2, int length2, int i, int j, int d) {
        if(i == length1-1) return d + length2 - 1 - j;
        if(j == length2-1) return d + length1 - 1 - i;
        if(word1[i] == word2[j]) {
            return recurse(word1, length1, word2, length2, i+1, j+1, d);
        } 
        else {
            int d1 = recurse(word1, length1, word2, length2, i+1, j, d+1);
            int d2 = recurse(word1, length1, word2, length2, i, j+1, d+1);
            int d3 = recurse(word1, length1, word2, length2, i+1, j+1, d+1);
            int min = d1;
            if(d2 < min) min = d2;
            if(d3 < min) min = d3;
            return min;
        }
    }
};
