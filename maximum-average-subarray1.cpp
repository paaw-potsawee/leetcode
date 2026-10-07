// https://leetcode.com/problems/maximum-average-subarray-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxNum;
        int sum = 0;
        
        for (int i = 0; i < k; i++) {
            maxNum += nums[i];            
        }
        sum = maxNum;
        
        for (int i = 0; i < nums.size() - k; i++) {
            // remove first element
            sum -= nums[i];            
            // add next element of window
            sum += nums[i + k];            
            
            if (sum > maxNum) maxNum = sum;
        }

        
        return static_cast<double>(maxNum) / k;        

    }
};