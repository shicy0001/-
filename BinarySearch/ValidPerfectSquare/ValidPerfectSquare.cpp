/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-perfect-square
作者：shicy
日期：2019-11-30

给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        unsigned long low = 0, high = num, mid;
        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(mid * mid == num)
                return true;
            else if(mid * mid > num)
                high = mid -1;
            else
                low = mid + 1;
        }
        return false;
    }
};