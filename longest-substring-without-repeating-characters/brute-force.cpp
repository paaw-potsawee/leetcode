// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int prev[128];
        memset(prev, -1, sizeof(prev));
        int maxLen = 0;
        int lenCount = 1;
        prev[s[0]] = 0;
        int i = 1;
        while (i < s.size()){
            if (prev[s[i]] == -1) {
                lenCount++;
                // append to prev 
                prev[s[i]] = i;
            } else {
                maxLen = lenCount > maxLen ? lenCount : maxLen;
                lenCount = 1;
                // go back to i + 1 at duplicate position
                i = prev[s[i]] + 1;
                // clear prev list
                memset(prev, -1, sizeof(prev));
                // set back to duplicate last element
                prev[s[i]] = i;
            }
            i++;
        }
        maxLen = lenCount > maxLen ? lenCount : maxLen;
        return maxLen;
    }
};

int main() {
    auto sol = Solution();
    string str = "bbbbbbbbbbbbb";
    // string str = "abcabcbb";
    // string str = "aab";
    // string str = "pwwkew";
    // string str = "dvdf";
    cout << sol.lengthOfLongestSubstring(str);
    return 0;
}
