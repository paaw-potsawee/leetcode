// https://leetcode.com/problems/merge-strings-alternately/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
    string mergeAlternately(string word1, string word2) {
        size_t n1 = word1.length();
        size_t n2 = word2.length();
        int i1 = 0;
        int i2 = 0;
        string result = "";
        while(true) {
            if (i1 < n1)
                result.push_back(word1[i1++]);
            if (i2 < n2)
                result.push_back(word2[i2++]);
            if (i1 >= n1 && i2 >= n2) break;
        }
        return result;
    }
};