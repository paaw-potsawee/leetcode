// https://leetcode.com/problems/build-an-array-with-stack-operations/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        const int iMax = target.size();
        vector<string> res = {};
        int current = 0;
        int iTarget = 0;

        for(int i = 0; i < n; i++) {
            if (iTarget == iMax) break;
            current = i + 1;
            res.push_back("Push");

            if (target[iTarget] == current) {
                // valid stack keep pushing
                iTarget++;
            } else {
                res.push_back("Pop");
            }
        }

        return res;
    }
};