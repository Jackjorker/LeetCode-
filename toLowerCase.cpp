/*
给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。

?

示例 1：

输入：s = "Hello"
输出："hello"
示例 2：

输入：s = "here"
输出："here"
示例 3：

输入：s = "LOVELY"
输出："lovely"



*/





//方法一 ： 

class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
            s[i]+=32;
        }
        return s;
    }
};


//方法2：
class solution2{
  public :
    string tolowerCase(string s){
      for(char & ch : s){
        tolower(ch);
      }
      return s;
    }
}