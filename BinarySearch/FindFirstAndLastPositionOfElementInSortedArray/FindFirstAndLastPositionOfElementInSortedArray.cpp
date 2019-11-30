/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
作者：shicy
日期：2019-11-30

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0, mid = 0, high = nums.size()-1;
        vector<int> res;
        
        if(high == -1)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
            
        
        //the begining index of the target
        while(low +1 < high)
        {
            mid = low + (high -low)/2;
            if(nums[mid] > target)
                high = mid-1;
            else if(nums[mid] == target)
                high = mid;
            else
                low = mid;
        }
        
        if(nums[low] == target)
            res.push_back(low);
        else if(nums[high] == target)
            res.push_back(high);
        else
            res.push_back(-1);
        
        //the end index of the target
        low = 0, mid = 0, high = nums.size()-1;
        while(low +1 < high)
        {
            mid = low + (high -low)/2;
            if(nums[mid] > target)
                high = mid;
            else if(nums[mid] == target)
                low = mid;
            else
                low = mid +1;
        }
        if(nums[high] == target)
            res.push_back(high);
        else if (nums[low] == target)
            res.push_back(low);
        else
            res.push_back(-1);
        
        return res;
    }
};