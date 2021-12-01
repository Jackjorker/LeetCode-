/*
给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。

示例 1：

输入：s = "leetcode"
输出：2
解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。


示例 2：

输入：s = "abbcccddddeeeeedcba"
输出：5
解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。

示例 3：

输入：s = "triplepillooooow"
输出：5

**/


class Solution {
public:
    int maxPower(string s) {
        int res = 0;//定义返回int类型
        
        int a = 1;//定义一个变量，存储字符串字符相同的字串长度
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == s[i+1]){
                a++;
            }
            else {
                res = max(res,a);//取res,a之间最大的值
                a = 1;
            }
        }
        return res;
    }
};