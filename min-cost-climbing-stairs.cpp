// https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include <iostream>
using namespace std;

class Solution {
private:
    int min(int a, int b) {
        return a > b ? b : a;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
