// https://leetcode.com/problems/find-the-highest-altitude/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxValue = 0;
        for (int i = 0; i < gain.size(); i++) {
            sum += gain[i];
            if (sum > maxValue) {
                maxValue = sum;
            }
        }
        return maxValue;
    }
};