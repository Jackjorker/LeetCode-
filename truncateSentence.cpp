
/***
 * 
 * ���� ��һ�������б��б��еĵ���֮���õ����ո�������Ҳ�����ǰ����β��ո�ÿ�����ʽ��ɴ�СдӢ����ĸ��ɣ����������ţ���

���磬"Hello World"��"HELLO" �� "hello world hello world" ���Ǿ��ӡ�
����һ������ s?????? ��һ������ k?????? �����㽫 s?? �ض� ?��???ʹ�ضϺ�ľ��ӽ��� ǰ k?????? �����ʡ����� �ض� s?????? ��õ��ľ��ӡ�

ʾ�� 1��

���룺s = "Hello how are you Contestant", k = 4
�����"Hello how are you"
���ͣ�
s �еĵ���Ϊ ["Hello", "how" "are", "you", "Contestant"]
ǰ 4 ������Ϊ ["Hello", "how", "are", "you"]
��ˣ�Ӧ������ "Hello how are you"
ʾ�� 2��

���룺s = "What is the solution to this problem", k = 4
�����"What is the solution"
���ͣ�
s �еĵ���Ϊ ["What", "is" "the", "solution", "to", "this", "problem"]
ǰ 4 ������Ϊ ["What", "is", "the", "solution"]
��ˣ�Ӧ������ "What is the solution"



 * 
 * 
 * 
*/



class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;//����һ�������ַ���
        if( k  == 0)
        return 0;//���kΪ0�� res�ַ������ؿգ�
        for(int i  = 0; i < s.size(); ++i){
            //res.push_back(s[i]);//�������һ����������������res�ַ���ĩβ��һ���ո�����
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