
/***
 * 
 * 句子 是一个单词列表，列表中的单词之间用单个空格隔开，且不存在前导或尾随空格。每个单词仅由大小写英文字母组成（不含标点符号）。

例如，"Hello World"、"HELLO" 和 "hello world hello world" 都是句子。
给你一个句子 s?????? 和一个整数 k?????? ，请你将 s?? 截断 ?，???使截断后的句子仅含 前 k?????? 个单词。返回 截断 s?????? 后得到的句子。

示例 1：

输入：s = "Hello how are you Contestant", k = 4
输出："Hello how are you"
解释：
s 中的单词为 ["Hello", "how" "are", "you", "Contestant"]
前 4 个单词为 ["Hello", "how", "are", "you"]
因此，应当返回 "Hello how are you"
示例 2：

输入：s = "What is the solution to this problem", k = 4
输出："What is the solution"
解释：
s 中的单词为 ["What", "is" "the", "solution", "to", "this", "problem"]
前 4 个单词为 ["What", "is", "the", "solution"]
因此，应当返回 "What is the solution"



 * 
 * 
 * 
*/



class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;//定义一个返回字符串
        if( k  == 0)
        return 0;//如果k为0， res字符串返回空；
        for(int i  = 0; i < s.size(); ++i){
            //res.push_back(s[i]);//如果将这一句代码放在这里，会出现res字符串末尾有一个空格的情况
            if(s[i] == ' '){
                k--;
            }
            if(k  ==  0)
            break;
            res.push_back(s[i]);
        }

        return res;
    }
};