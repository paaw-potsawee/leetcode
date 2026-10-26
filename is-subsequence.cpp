// https://leetcode.com/problems/is-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ps = 0;
        int pt = 0;
        while(ps < s.length() && pt < t.length()) {
            if (s[ps] == t[pt]) {
                ps++;
            }
            pt++;
        }
        return ps == s.length();
    }
};
