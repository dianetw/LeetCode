/*
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 * Constraints:
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 */
class Solution {
private:
    bool binarySearch(vector<int> &nums, int target, int low, int high) {
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos, endPos;
        int low = 0;
        int high = nums.size() - 1;
        bool search = binarySearch(nums, target, low, high);
        if (nums.size() == 0) {  // if array is empty, return {-1, -1}
            return {-1, -1};
        }
        if (!search) {
            return {-1, -1};
        }

        firstPos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        endPos = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1;
        return {firstPos, endPos};
    }
};
