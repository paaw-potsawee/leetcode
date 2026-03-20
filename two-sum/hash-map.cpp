// https://leetcode.com/problems/two-sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result = {};
        unordered_map<int, int> umap;
        
        umap[nums[0]] = 0; 
        for (int i = 1; i < nums.size(); i++) {
            if (umap.contains(target - nums[i]) == true) {
                result.push_back(i);
                result.push_back(umap[target - nums[i]]);
                return result; 
            } else {
                umap[nums[i]] = i;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    // vector<int> nums = {3,2,4};
    auto sol = Solution();
    auto result = sol.twoSum(nums, 6);
    for (auto i : result) {
        cout << i << ' ';
    }
    return 0;
}
