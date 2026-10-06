// https://leetcode.com/problems/move-zeroes/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ix = 1;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (i > ix) {
                ix = i;
            }
            // move ix to next non-zero integer
            // if no next non-zero break the loop
            while (ix < len && nums[ix] == 0) {
                ix++;
            }

            // if current is zero swap
            if (nums[i] == 0 && ix < len) {
                nums[i] = nums[ix];
                nums[ix] = 0;
            }
        }
    }
};

int main() {
    auto sol = Solution();
    // vector<int> nums = {0,1,0,3,12};
    vector<int> nums = {0};
    sol.moveZeroes(nums);
    
    for (auto a:nums) {
        cout << a << " ";
    }
    return 0;
}