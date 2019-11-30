/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
作者：shicy
日期：2019-11-30

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:
输入: 2.00000, 10
输出: 1024.00000

示例 2:
输入: 2.10000, 3
输出: 9.26100

示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
 */

class Solution {
public:
    double myPow(double x, int n) {
        
        double temp = 0;
        long N = n;
        
        if(N<0)
        {
            N = -N;
            x = 1/x;
        }
           
        
        if (x == 0.0)
            return 0;
        
        if(N == 0)
            return 1;
        else if (N == 1)
            return x;
        
        temp = myPow(x, N/2);
        if(N%2 == 0)
            return temp * temp;
        
        else
                return temp * temp * x;
        
    }
};