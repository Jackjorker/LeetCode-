
/*

Ϊ�˲���������б�¶�ּ�������־������������Ҫ����ĸ����ɵ����������˼��

����һ������� (ransomNote) �ַ�����һ����־(magazine)�ַ������ж� ransomNote �ܲ����� magazines ������ַ����ɡ�

������Թ��ɣ����� true �����򷵻� false ��

magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�

?

ʾ�� 1��

���룺ransomNote = "a", magazine = "b"
�����false
ʾ�� 2��

���룺ransomNote = "aa", magazine = "ab"
�����false
ʾ�� 3��

���룺ransomNote = "aa", magazine = "aab"
�����true






*/



class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //����ַ���magzine�ĳ���С��ransomNote�ĳ��ȣ�������Ҫ��return false
        if(magazine.size() < ransomNote.size()){
            return false;

        }
        //����һ������26����ĸ������������cnt
        vector<int> cnt(26);
        //��magzine�ַ������ַ�һһ����cnt֮��
        for(auto &i : magazine){
            cnt[i - 'a']++;
        }
        //����ransomNoteһ��һ����ȥmagzine���ַ����������magzineĳһ�ַ������������������false
        for(auto & i : ransomNote){
            cnt[i - 'a']--;
            if(cnt[i -  'a'] < 0)
            return false;
        }
        //���򷵻�true
        return true;
    }
};