/*
����һ������Ϊ n ���������� score ������ score[i] �ǵ� i λ�˶�Ա�ڱ����еĵ÷֡����е÷ֶ� ������ͬ ��

�˶�Ա�����ݵ÷� �������� ���������ε� 1 ���˶�Ա�÷���ߣ����ε� 2 ���˶�Ա�÷ֵ� 2 �ߣ��������ơ��˶�Ա�����ξ��������ǵĻ������

���ε� 1 ���˶�Ա����� "Gold Medal" ��
���ε� 2 ���˶�Ա������ "Silver Medal" ��
���ε� 3 ���˶�Ա��ͭ�� "Bronze Medal" ��
�����ε� 4 ���� n ���˶�Ա��ֻ�ܻ�����ǵ����α�ţ��������ε� x ���˶�Ա��ñ�� "x"����
ʹ�ó���Ϊ n ������ answer ���ػ񽱣����� answer[i] �ǵ� i λ�˶�Ա�Ļ������

ʾ�� 1��

���룺score = [5,4,3,2,1]
�����["Gold Medal","Silver Medal","Bronze Medal","4","5"]
���ͣ�����Ϊ [1st, 2nd, 3rd, 4th, 5th] ��


ʾ�� 2��

���룺score = [10,3,8,9,4]
�����["Gold Medal","5","Bronze Medal","Silver Medal","4"]
���ͣ�����Ϊ [1st, 5th, 3rd, 2nd, 4th] ��



*/



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();//����score�ĳ���
        string nums[3] = {"Gold Medal","Silver Medal","Bronze Medal"};//ǰ������string����
        vector<pair<int,int>> arr;//��i��score[i]��Ӧ��
        for(int i = 0; i < n; ++i){
            arr.emplace_back(make_pair(-score[i], i));//��score[i]ǰ��Ӹ��ţ�����֮���������
        }
        sort(arr.begin(),arr.end());//����С�������򣬸���ԽС�ģ���score[i]Խ��
        vector<string> answer(n);
        for(int i = 0 ; i < n; ++i ){
            if(i >= 3){
                answer[arr[i].second] = to_string(i + 1);
            }else{
                answer[arr[i].second] = nums[i];
            }
        }
        return answer;
        

    }
};