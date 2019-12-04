/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
作者：shicy
日期：2019-12-03

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

Solution1:暴力法就不说了，时间复杂度O(n^2)。

Solution2：为了优化运行时间，我们需要一种更有效的方法搜索目标元素(target-num[i])，若存在，找出它的下标。
           可借助哈希表，通过两次迭代实现。第一次迭代，把元素存储在哈希表中，key是元素值，value是该元素在nums中的下标；第二次迭代，寻找目标元素(target-nums[i])是否在表中。
           时间复杂度O(n)，空间复杂度O(n)。

Solution3：同样借助哈希表，只用一次迭代实现。先检查表中是否存在目标元素(target-nums[i])，若不存在则把元素添加到表中，否则表示已经找到对应解，立即返回。
            时间复杂度O(n)，空间复杂度O(n)。
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> result;

        //1.put numbers into map
        for (int i = 0;i< nums.size();i++)
            m.insert(make_pair(nums[i], i));

        //2.find target-nums[i]
        for(int i = 0;i < nums.size();i++){
            if(m.find(target -nums[i]) != m.end()){
                if(m[target -nums[i]] != i)
                {
                    result.push_back(i);
                    result.push_back(m[target -nums[i]]);
                    break;
                }
            }    
        }
        return result;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> result;
        
        for (int i = 0;i< nums.size();i++){
            if(m.find(target - nums[i]) == m.end())
                m[nums[i]] = i;
            else{
                result.push_back(i);
                result.push_back(m[target - nums[i]]);
                break;
            } 
        }
        return result;
    }
};