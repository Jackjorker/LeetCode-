/*
����һ���ַ��� s �������ַ����еĴ�д��ĸת������ͬ��Сд��ĸ�������µ��ַ�����

?

ʾ�� 1��

���룺s = "Hello"
�����"hello"
ʾ�� 2��

���룺s = "here"
�����"here"
ʾ�� 3��

���룺s = "LOVELY"
�����"lovely"



*/





//����һ �� 

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


//����2��
class solution2{
  public :
    string tolowerCase(string s){
      for(char & ch : s){
        tolower(ch);
      }
      return s;
    }
}