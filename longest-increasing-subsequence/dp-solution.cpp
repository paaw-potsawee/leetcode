// https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto len = nums.size();
        int maxLenght = 1;
        vector<int> dp(len, 1);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = this->max(dp[i], dp[j] + 1);
                    maxLenght = this->max(dp[i], maxLenght);
                }
            }
        }
        return maxLenght;
    }

    int max(int a,int b) {
        return a > b ? a : b;
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