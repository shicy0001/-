/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
作者：shicy
日期：2019-11-30

实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去
 */

int mySqrt(int x){
    
    unsigned long low = 0, mid = 0, high = x;
    while(low + 1 < high)
    {
        mid = low + (high - low)/2;
        
        if(mid * mid == x)
            return mid;
        else if(mid * mid > x)
            high = mid;
        else
            low = mid;
    }
    
    if(low * low == x)
        return low;
    else if (high * high == x)
        return high;
    else
        return low;
}