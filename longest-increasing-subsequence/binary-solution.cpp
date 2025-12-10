// https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub = {nums[0]};
        auto len = nums.size();
        for (int i = 1; i < len; i++) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                sub[this->binarySearch(sub,nums[i])] = nums[i];
            }
        }
        return sub.size();
    }
    int binarySearch(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (r > l) {
            mid = l + (r - l) / 2; 
            if (val <= nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    auto sol = Solution();
    vector<vector<int>> testCases = {
        {10,9,2,5,3,7,101,18},
        {7,7,7,7,7,7,7},
        {0,1,0,3,2,3},
    };
    for (vector<int>& testCase: testCases) {
        cout << "Input is: ";
        for (int num: testCase) {
            cout << num << " ";
        }
        cout << "\n Result: ";
        cout << sol.lengthOfLIS(testCase) << endl;
    }
    return 0;
}