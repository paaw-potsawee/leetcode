// https://leetcode.com/problems/find-peak-element/description/
class Solution {
private:
    bool comp(vector<int>& nums, int mid) {
        if (mid - 1 < 0 && mid + 1 >= nums.size()) {
            return true;
        } 
        if (mid - 1 < 0) {
            return nums[mid] > nums[mid + 1];
        }
        if (mid + 1 >= nums.size()) {
            return nums[mid] > nums[mid - 1];
        }
        return nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1];
    }
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int mid = nums.size() / 2;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (comp(nums, mid)) return mid;
            else if (mid - 1 < 0 || nums[mid] > nums[mid - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
