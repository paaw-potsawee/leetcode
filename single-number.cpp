// https://leetcode.com/problems/single-number/description/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int16_t t = 0;
        for (int16_t i = 0; i < nums.size(); i++) {
            t = t ^ nums[i];
        }
        return t;
    }
};
