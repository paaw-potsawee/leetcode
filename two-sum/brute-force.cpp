// https://leetcode.com/problems/two-sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result = {};
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }                
            }            
        }
        return result;
    }
};

int main() {
    // vector<int> nums = {2, 7, 11, 15};
    vector<int> nums = {3,2,4};
    auto sol = Solution();
    auto result = sol.twoSum(nums, 6);
    for (auto i : result) {
        cout << i << ' ';
    }
    return 0;
}