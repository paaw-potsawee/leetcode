//https://leetcode.com/problems/triangle/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto n = triangle.size();
        size_t m;
        int result = 0;
        int prev = 0;
        result += triangle[0][0];
        vector<int> dp(n,0);
        dp[0] = result;
        for (int i = 1; i < n; i++) {
            m = triangle[i].size();
            prev = dp[0];
            dp[0] = dp[0] + triangle[i][0];
            result = dp[0];
            for (int j = 1; j < m - 1; j++) {
                if (prev > dp[j]) {
                    prev = dp[j];
                    dp[j] = dp[j] + triangle[i][j];
                } else {
                    int tmp = dp[j];
                    dp[j] = prev + triangle[i][j];
                    prev = tmp;
                }
                if (dp[j] < result) {
                    result = dp[j];
                }
            }
            dp[m - 1] = prev + triangle[i][m - 1];
            if (dp[m - 1] < result) result = dp[m - 1];
        }
        return result;
    }
};

int main() {
    // vector<vector<int>> nums = {{2},{3,4},{6,5,7},{4,1,8,3}};
    // vector<vector<int>> nums = {{-10}};
    vector<vector<int>> nums = {{-1},{2,3},{1,-1,-3}};
    // vector<vector<int>> nums = {{1},{2,3}};
    auto sol = Solution();
    cout << sol.minimumTotal(nums) << endl;
    return 0;
}