// https://leetcode.com/problems/removing-stars-from-a-string/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                s[j] = s[i];
                j++;
            } else {
                j--;
            }
        }
        s.resize(j);
        return s;
    }
};
