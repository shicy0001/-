/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
作者：shicy
日期：2019-12-18


给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


解法1：
暴力法，时间复杂度为O(n^2)

解法2：
将字符串存入哈希表，插入每个字符之前先检查哈希表中是否存在该字符，若存在则覆盖式插入
时间复杂度：O(n)
tag：哈希表、滑动窗口


 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int> m;
        int lastrepeatpos = -1, maxlength = 0;

        for(int i =0;i < s.size();i++){

            if(m.find(s[i]) != m.end() && lastrepeatpos < m[s[i]]){
                lastrepeatpos = m[s[i]];
            }
            maxlength = maxlength < (i-lastrepeatpos) ? (i-lastrepeatpos) : maxlength;
            m[s[i]] = i;
        }

        return maxlength;
    }
};
