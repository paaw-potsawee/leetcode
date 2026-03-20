// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int start, end, maxLen = 1;
        start = 0;
        end = 1;
        int track[128];
        memset(track, -1, sizeof(track));
        track[s[0]] = 0;
        while (end < s.size()) {
            // if track[s[end]] == -1 set value to end as last seen checking and upate max length before increment end value
            // if track[s[end]] < start set last seen to end value update end and track
            if (track[s[end]] == -1 || track[s[end]] < start) {
                track[s[end]] = end;
                end++;
                maxLen = maxLen < end - start ? end - start : maxLen;
            } else {
            // if track[s[end]] >= start last seen value after start
            // update start to last seen + 1 move and set track for end
                start = track[s[end]] + 1;
                track[s[end]] = end;
                end++;
            }

        }
        maxLen = maxLen < end - start ? end - start : maxLen;
        return maxLen;
    }
};

int main() {
    auto sol = Solution();
    // string str = "bbbbbbbbbbbbb";
    // string str = "abcabcbb";
    // string str = "aab";
    // string str = "pwwkew";
    string str = "dvdf";
    cout << sol.lengthOfLongestSubstring(str);
    return 0;
}

