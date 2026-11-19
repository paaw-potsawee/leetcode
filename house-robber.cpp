// https://leetcode.com/problems/house-robber/description/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int mm = 0;
        for (int i = 0; i < n; i++) {
            if (i > 2) {
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
                mm = max(dp[i], mm);
            } else if (i == 2) {
                dp[i] = nums[i] + dp[i - 2];
                mm = max(dp[i], mm);
            } else {
                dp[i] = nums[i];
                mm = max(mm, nums[i]);
            }
        }
        return mm;
    }
};
