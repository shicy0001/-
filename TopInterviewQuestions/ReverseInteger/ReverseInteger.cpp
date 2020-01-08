/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
作者:shicy
日期：2019-01-08

题目描述：
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21
注意:
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

solutioin:
通过数学方法，对10取余取个位数。要考虑两个问题：1.最后一位是0；2.反转后可能会溢出，超过32位整数表示范围。
如何判断是否会溢出:res*10+y > maxint -> res>(maxint-y)/10 -> res > maxint/10 - y/10 -> res > maxint/10
 */

class Solution {
public:
    int reverse(int x) {
        int y = 0,res = 0;
        int maxint = 2147483647,minint = -2147483648;
        
        while(x!=0)
        {
            y = x%10;
            if(res > maxint/10 || res < minint/10)
                return 0;

            res = res * 10 + y;
            x=x/10;
        }
        
        return res;        
    }
};