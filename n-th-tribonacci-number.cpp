// https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n < 3) return 1;
        vector<int> dp = {0, 1, 1};
        int i  = 3;
        for (i = 3; i < n; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
        }
        return dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
};
